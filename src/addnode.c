#include "addnode.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "Node.h"
#include "avlint.h"

/*function that use to add node that can use for universal data
by implementing different type of compare function
*/


int addNode(Node **nodePtr,Node *newNode,Compare IntegerCompare){
  int height;     //it return height to let use determine height change
  if(*nodePtr == NULL){
    *nodePtr = newNode;
    (*nodePtr)->left =NULL;
    (*nodePtr)->right =NULL;
    height =1;
    return height;
   }
  else{
    int Result = IntegerCompare((void *)newNode->data,*nodePtr);
    if (Result == 1)      //if smaller it go left
     {
     height = addNode(&(*nodePtr)->left,newNode,IntegerCompare);
       if(height==1){       //there are height change
       (*nodePtr)->balanceFactor -= 1;
         if((*nodePtr)->balanceFactor==0)
         height=0;
       }
     else
     (*nodePtr)->balanceFactor =(*nodePtr)->balanceFactor;

     }
     else if (Result ==-1)      //larger go left
     {
     height = addNode(&(*nodePtr)->right,newNode,IntegerCompare);
       if(height==1){
       (*nodePtr)->balanceFactor += 1;
         if((*nodePtr)->balanceFactor==0)
           height=0;
         }
       else
         (*nodePtr)->balanceFactor =(*nodePtr)->balanceFactor;
     }
   }
   if((*nodePtr)->balanceFactor >= 2) {      //rotate function
       avlBalanceRightTree(&(*nodePtr));
       if((*nodePtr)->balanceFactor == 0)
         height=0;
     }
   else if((*nodePtr)->balanceFactor <= -2){
       avlBalanceLeftTree(&(*nodePtr));
       if((*nodePtr)->balanceFactor == 0)
         height=0;
       }
   else{
      *nodePtr = *nodePtr;
     }
       return height;
}
