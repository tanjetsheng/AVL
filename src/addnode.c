#include "addnode.h"


Node *addNode(Node **nodePtr,Node *newNode){
  if(*nodePtr == NULL){
    *nodePtr == newNode;
     return *nodePtr;
   }
  else{
  if((*nodePtr)->data > (newNode)->data){
    (*nodePtr)->left = addNode((*nodePtr)->left,newNode);
  }
  if((*nodePtr)->data <(newNode)->data){
    (*nodePtr)->right = addNode((*nodePtr)->right,newNode);
  }
  }
  return *nodePtr;
}
