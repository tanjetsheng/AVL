#include "addnode.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"


int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandChild = node->right->left;

  if(child->bf > 0 ){
    node->bf = 0;
    child->bf = 0;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->bf == 0){
    node->bf = 1;
    child->bf = -1;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->bf == -1){
    if(grandChild->bf == -1){
      node->bf = 0;
      child->bf = 1;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->bf == 0){
      node->bf = 0;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->bf == 1){
      node->bf = -1;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
  }
  return 0;
}

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandChild = node->left->right;

  if(child->bf < 0 ){
    node->bf = 0;
    child->bf = 0;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->bf == 0){
    node->bf = -1;
    child->bf = 1;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->bf == 1){
    if(grandChild->bf == -1){
      node->bf = 1;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->bf == 0){
      node->bf = 0;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->bf == 1){
      node->bf = 0;
      child->bf = -1;
      grandChild->bf = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
  }
  return 0;
}

int addNode(Node **nodePtr,Node *newNode){
  int height;
  if(*nodePtr == NULL){
    *nodePtr = newNode;
    (*nodePtr)->left =NULL;
    (*nodePtr)->right =NULL;
    height =1;
    return height;
   }
  else{
  if((*nodePtr)->data > (newNode)->data){
    height = addNode((&(*nodePtr)->left),newNode);
    if(height == 1)
      (*nodePtr)->bf -= 1;
    if((*nodePtr)->bf == 0)
          height = 0;
    else {
      (*nodePtr)->bf=(*nodePtr)->bf;
    }

  }
  else if((*nodePtr)->data <(newNode)->data){
    height = addNode((&(*nodePtr)->right),newNode);
    if(height == 1)
    (*nodePtr)->bf += 1;
    if((*nodePtr)->bf == 0)
          height = 0;
    else {
        (*nodePtr)->bf=(*nodePtr)->bf;
          }


    //return *nodePtr;
  }
    }
  if((*nodePtr)->bf >= 2)
        avlBalanceLeftTree(&(*nodePtr));
  else if((*nodePtr)->bf <= -2)
        avlBalanceRightTree(&(*nodePtr));
    else{
        *nodePtr = *nodePtr;
      }
    return height;

}

/*Node *addNodeBalance(Node **nodePtr,Node *newNode){
  addNode(Node **nodePtr,Node *newNode);

}
*/
