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

Node *addNode(Node **nodePtr,Node *newNode){
  if(*nodePtr == NULL){
    *nodePtr = newNode;
    return *nodePtr;
   }
  else{
  if((*nodePtr)->data > (newNode)->data){
      (*nodePtr)->bf -= 1;
    (*nodePtr)->left = addNode((&(*nodePtr)->left),newNode);

    //return *nodePtr;
  }
  else if((*nodePtr)->data <(newNode)->data){
    (*nodePtr)->bf += 1;
    (*nodePtr)->right = addNode((&(*nodePtr)->right),newNode);

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
    return *nodePtr;

}

/*Node *addNodeBalance(Node **nodePtr,Node *newNode){
  addNode(Node **nodePtr,Node *newNode);

}
*/
