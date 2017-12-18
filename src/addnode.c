#include "addnode.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "Node.h"
#include "avlint.h"




int addNode(Node **nodePtr,Node *newNode,Compare IntegerCompare){
  int height;
  if(*nodePtr == NULL){
    *nodePtr = newNode;
    (*nodePtr)->left =NULL;
    (*nodePtr)->right =NULL;
    height =1;
    return height;
   }
  else{
    int Result = IntegerCompare((void *)newNode->data,*nodePtr);
    if (Result == 1)
     {
     height = addNode(&(*nodePtr)->left,newNode,IntegerCompare);
       if(height==1){
       (*nodePtr)->balanceFactor -= 1;
         if((*nodePtr)->balanceFactor==0)
         height=0;
       }
     else
     (*nodePtr)->balanceFactor =(*nodePtr)->balanceFactor;

     }
     else if (Result ==-1)
     {
     height = addNode(&(*nodePtr)->right,newNode,IntegerCompare);
       if(height==1){
       (*nodePtr)->balanceFactor += 1;
         if((*nodePtr)->balanceFactor==0)
           height=0;;
         }
       else
         (*nodePtr)->balanceFactor =(*nodePtr)->balanceFactor;
     }
   }
   if((*nodePtr)->balanceFactor >= 2)
       avlBalanceLeftTree(&(*nodePtr));
   else if((*nodePtr)->balanceFactor <= -2)
       avlBalanceRightTree(&(*nodePtr));
   else{
      *nodePtr = *nodePtr;
     }
       return height;
}
