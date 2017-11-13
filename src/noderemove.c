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
  int change;
  if((*nodePtr) == NULL){
    return NULL;
  }
  else if((*nodePtr)->data > (nodeToRemove)->data){
    if((*nodePtr)->left == nodeToRemove && (*nodePtr)->right != NULL){
      (*nodePtr)->left = removeNode((&(*nodePtr)->left),nodeToRemove);
      change = 0;
    }
    else if((*nodePtr)->left == nodeToRemove && (*nodePtr)->right == NULL){
    (*nodePtr)->left = removeNode((&(*nodePtr)->left),nodeToRemove);
  //  (*nodePtr)->bf +=1;
    change = 1;
  }
  else{
    (*nodePtr)->left = removeNode((&(*nodePtr)->left),nodeToRemove);
    change = 0;
  }
  if(change = 1){
    (*nodePtr)->bf +=1;
  }
  else{
    (*nodePtr)->bf = (*nodePtr)->bf;
    }
}

  else if((*nodePtr)->data < (nodeToRemove)->data){
    (*nodePtr)->right = removeNode((&(*nodePtr)->right),nodeToRemove);
      (*nodePtr)->bf -=1;
  }
  else  if((*nodePtr)->data == (nodeToRemove)->data){
    if(((*nodePtr)->left == NULL) && ((*nodePtr)->right == NULL)){
      (*nodePtr)->bf = 0;
      *nodePtr = NULL;
    }
    else if(((*nodePtr)->left != NULL) && ((*nodePtr)->right != NULL)){
      Node *temp = getRightValue((*nodePtr)->right);
      removeNode(&(*nodePtr),temp);
      temp->bf = (*nodePtr)->bf;
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
    }
      else if(((*nodePtr)->left != NULL) && ((*nodePtr)->right == NULL)){
      //Node *root = (*nodePtr)->left;
      Node *temp = getLeftValue((*nodePtr)->left);
      removeNode(&(*nodePtr),temp);
      temp->bf = (*nodePtr)->bf;
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
    }
    else if(((*nodePtr)->left == NULL) && ((*nodePtr)->right != NULL)){
      Node *temp = getRightValue((*nodePtr)->right);
      removeNode(&(*nodePtr),temp);
      temp->bf = (*nodePtr)->bf;
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
    }
    else {
      return NULL;
    }
    return *nodePtr;
  }
   if((*nodePtr)->bf >= 2){
        avlBalanceLeftTree(&(*nodePtr));
      }
  else if((*nodePtr)->bf <= -2){
        avlBalanceRightTree(&(*nodePtr));
      }
  return *nodePtr;
}
