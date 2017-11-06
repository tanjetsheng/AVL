#include "noderemove.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"

Node *getValue(Node *nodePtr){
  if(nodePtr->left!=NULL){
    getValue(nodePtr->left);
  }
  else{
    return nodePtr;
  }
}
Node *removeNode(Node **nodePtr,Node *nodeToRemove){
  if(*nodePtr == nodeToRemove){
      *nodePtr = NULL;
  }
  else if((*nodePtr)->left->data == nodeToRemove->data){
    (*nodePtr)->left = NULL;
    (*nodePtr)->bf += 1;
  }
  return *nodePtr;
}
