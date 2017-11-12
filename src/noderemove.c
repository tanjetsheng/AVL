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
  if((*nodePtr)->data > (nodeToRemove)->data){
    *nodePtr = removeNode((&(*nodePtr)->left),nodeToRemove);
  }
  else if((*nodePtr)->data < (nodeToRemove)->data){
    *nodePtr = removeNode((&(*nodePtr)->right),nodeToRemove);
  }
  else if((*nodePtr)->data == (nodeToRemove)->data){
    if(((*nodePtr)->left == NULL) && ((*nodePtr)->right == NULL)){
      *nodePtr = NULL;
    }
    else if(((*nodePtr)->left != NULL) && ((*nodePtr)->right != NULL)){
    //  Node *root = (*nodePtr)->right;
      Node *temp = getValue((*nodePtr)->right);
     removeNode(&(*nodePtr)->right,temp);
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
    //  return *nodePtr;

    }
      else if(((*nodePtr)->left != NULL) && ((*nodePtr)->right == NULL)){
      Node *root = (*nodePtr)->left;
      Node *temp = getValue(root);
      (*nodePtr)->left = removeNode(&(*nodePtr)->left,temp);
      temp->left = (*nodePtr)->left;
      temp->right = (*nodePtr)->right;
      *nodePtr = temp;
      //return *nodePtr;

    }
  }
  return *nodePtr;
}
