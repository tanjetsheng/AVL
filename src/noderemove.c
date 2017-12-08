#include "noderemove.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"

Node *getRightValue(Node *nodePtr){
  if(nodePtr->left!=NULL){
    getRightValue(nodePtr->left);
  }
  else{
    return nodePtr;
  }
}

Node *getLeftValue(Node *nodePtr){
  if(nodePtr->right!=NULL){
    getLeftValue(nodePtr->right);
  }
  else{
    return nodePtr;
  }
}
Node *removeNode(Node **nodePtr,Node *nodeToRemove){
  Node *left = (*nodePtr)->left;
  Node *right = (*nodePtr)->right;
  if((*nodePtr) == NULL){
    return NULL;
  }
  else if((*nodePtr)->data > (nodeToRemove)->data){
    if((*nodePtr)->left == nodeToRemove && (*nodePtr)->bf == 0){
      (*nodePtr)->left = removeNode((&(*nodePtr)->left),nodeToRemove);
      (*nodePtr)->bf +=1;
      (*nodePtr)->change = 0;
    }
    else if((*nodePtr)->left == nodeToRemove && (*nodePtr)->bf != 0){
      (*nodePtr)->left = removeNode((&(*nodePtr)->left),nodeToRemove);
      (*nodePtr)->bf +=1;
      (*nodePtr)->change = 1;
    }
    else{
      (*nodePtr)->left = removeNode((&(*nodePtr)->left),nodeToRemove);
      if(left->change == 1){
        (*nodePtr)->change =1;
        (*nodePtr)->bf +=1;
      }
      else if(left->change == 0){
        (*nodePtr)->change = 0;
        (*nodePtr)->bf = (*nodePtr)->bf;
        }
    }

}

  else if((*nodePtr)->data < (nodeToRemove)->data){
    if((*nodePtr)->right == nodeToRemove && (*nodePtr)->bf == 0){
      (*nodePtr)->right = removeNode((&(*nodePtr)->right),nodeToRemove);
      (*nodePtr)->bf -=1;
      (*nodePtr)->change = 0;
    }
    else if((*nodePtr)->right == nodeToRemove && (*nodePtr)->bf != 0){
      (*nodePtr)->right = removeNode((&(*nodePtr)->right),nodeToRemove);
      (*nodePtr)->bf -=1;
      (*nodePtr)->change = 1;
    }
    else{
      (*nodePtr)->right = removeNode((&(*nodePtr)->right),nodeToRemove);
      if(right->change == 1){
        (*nodePtr)->change = 1;
        (*nodePtr)->bf -=1;
      }
      else if(right->change == 0){
        (*nodePtr)->change = 0;
        (*nodePtr)->bf = (*nodePtr)->bf;
        }
    }
  }
  else  if((*nodePtr)->data == (nodeToRemove)->data){
    if(((*nodePtr)->left == NULL) && ((*nodePtr)->right == NULL)){
      (*nodePtr)->bf = 0;
      *nodePtr = NULL;
    }
    else if(((*nodePtr)->left != NULL) && ((*nodePtr)->right != NULL)){
      Node *temp = getRightValue((*nodePtr)->right);
      removeNode(&((*nodePtr)->right),temp);
      if((*nodePtr)->right == NULL){
        temp->bf = (*nodePtr)->bf;
        temp->left = (*nodePtr)->left;
        (*nodePtr)->right = (*nodePtr)->right;
        *nodePtr = temp;
      }
      else{
      temp->bf = (*nodePtr)->bf;
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
    }
    }
      else if(((*nodePtr)->left != NULL) && ((*nodePtr)->right == NULL)){
      Node *temp = getLeftValue((*nodePtr)->left);
      removeNode(&((*nodePtr)->left),temp);
      if((*nodePtr)->left == NULL){
        temp->bf = (*nodePtr)->bf;
        temp->left = (*nodePtr)->left;
        (*nodePtr)->right = (*nodePtr)->right;
        *nodePtr = temp;
      }
      else{
      temp->bf = (*nodePtr)->bf;
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
    }
    }
    else if(((*nodePtr)->left == NULL) && ((*nodePtr)->right != NULL)){
      Node *temp = getRightValue((*nodePtr)->right);
      removeNode(&((*nodePtr)->right),temp);
      if((*nodePtr)->right == NULL){
        temp->bf = (*nodePtr)->bf;
        temp->left = (*nodePtr)->left;
        (*nodePtr)->right = (*nodePtr)->right;
        *nodePtr = temp;
      }
      else{
      temp->bf = (*nodePtr)->bf;
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
    }
    }
    else {
      return NULL;
    }
    return *nodePtr;
  }
  if((*nodePtr)->bf == 2){
       avlBalanceLeftTree(&(*nodePtr));
     }
 else if((*nodePtr)->bf == -2){
     avlBalanceRightTree(&(*nodePtr));
     }
  return *nodePtr;
}
/*
Node *findnearest(Node **rootPtr, int *heightchange)
{
Node *temp1;
Node *current = (*rootPtr)->left;
 if(current!=NULL){
      if(current->left != NULL)
         findnearest(&(*rootPtr)->left,heightchange);
     else{
         if(current->right !=NULL){
          (*rootPtr)->left = current->right;
          (*rootPtr)->bf +=1;
           current->right = NULL;
           *heightchange = 1;
         }
         else{
           (*rootPtr)->left = NULL;
           (*rootPtr)->bf +=1;
           if((*rootPtr)->bf >= 2)
              avlBalanceRightTree(&(*rootPtr));
           else if((*rootPtr)->bf <= -2)
              avlBalanceLeftTree(&(*rootPtr));
           else{
                (*rootPtr) = (*rootPtr);
               }
            if((*rootPtr)->bf!=0)
              *heightchange = 0;
           else
             *heightchange = 1;
         }
       return current;
        }
  }
  else
    temp1 = *rootPtr;
    *heightchange = 1;
     *rootPtr = NULL;
     return temp1;
 }
Node *avlRemove(Node **rootPtr, int data){
    int heightchange;
    Node *avlRemove = _avlRemove(rootPtr, data, &heightchange);
    if(avlRemove == NULL){
        printf("deleted value doesn't exist!");
    }
    return avlRemove;
}
Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange){
        Node *temp = *root;
       if (*root == NULL)
           return NULL; //heigh change
       if(nodeToRemove < (*root)->data ){
         temp=_avlRemove(&(*root)->left, nodeToRemove,heightchange);
         if(*heightchange == 1)
            (*root)->bf +=1;
            if((*root)->bf != 0)
            *heightchange = 0;
       }
       else if(nodeToRemove > (*root)->data ){
         temp=_avlRemove(&(*root)->right, nodeToRemove,heightchange);
         if(*heightchange==1)
            (*root)->bf -=1;
            if((*root)->bf != 0)
            *heightchange = 0;
       }
       else if(nodeToRemove == (*root)->data ){
           // node with only one child or no child
         if( ( (*root)->left == NULL) || ( (*root)->right == NULL) )
         {
             Node *current = (*root)->left ?  (*root)->left : (*root)->right;
             // No child case
             if (current == NULL)
             {
                 current = *root;
                 *root = NULL;
                 *heightchange=1; //heigh change
             }
             else // One child case
             {
              *root = current; // Copy the contents of the non-empty child
              *heightchange=1; // height change
             }
        }
        else// node with two children case
        {
            //find the nearest in removenode->right->most left
            Node* temp1 = findnearest(&(*root)->right,heightchange);
            //checking whether have heightchange ?
            if(*heightchange==1){
            (*root)->bf -=1;
              if((*root)->bf !=0)
              *heightchange = 0;
            }
            else{
            (*root)->bf=(*root)->bf;
            *heightchange = 0;
            }
            // Copy the nearest's data to this node
            if(temp1->right!=NULL){
              temp1->bf = ((*root)->bf);
              temp1->left = (*root)->left;
              (*root) = temp1;
            }
            else{
            temp1->bf = ((*root)->bf);
            temp1->left = (*root)->left;
            temp1->right= (*root)->right;
            (*root) = temp1;
            }
             if(*root==NULL){
               return temp;
             }
			       if((*root)->bf >= 2)
                avlBalanceRightTree(&(*root));
             else if((*root)->bf <= -2)
                 avlBalanceLeftTree(&(*root));
             else{
                *root = *root;
               }
            if((*root)->bf == 0)
            *heightchange = 0;
            else
            *heightchange = 1;
            return temp;
        }
    }
    if(*root==NULL){
          return temp;
        }
    if((*root)->bf >= 2)
          avlBalanceRightTree(&(*root));
    else if((*root)->bf <= -2)
          avlBalanceLeftTree(&(*root));
    else{
          *root = *root;
        }
    return temp;
}
*/
