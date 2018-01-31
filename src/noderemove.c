#include "noderemove.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"
#include "avlint.h"


Node *getValue(Node **nodePtr,int *height)        //get the value from the most
{                                                 //bottom and chack for the
  Node *temp;                                     //height change and perform
//  Node *child = (*nodePtr)->left;                   //height change

  if(*nodePtr == NULL)
  {
      *height = 1;
      return NULL;
  }
  if((*nodePtr)->left != NULL)
  {
      temp = getValue(&(*nodePtr)->left,height);
      if(*height == 1)
            (*nodePtr)->balanceFactor++;
      else
            (*nodePtr)->balanceFactor = (*nodePtr)->balanceFactor;
      if((*nodePtr)->balanceFactor >= 2)
              avlBalanceRightTree(&(*nodePtr));
      else if((*nodePtr)->balanceFactor <= -2)
              avlBalanceLeftTree(&(*nodePtr));
      else{
              *nodePtr = *nodePtr;
            }
     if((*nodePtr)->balanceFactor !=0)
            *height = 0;
    if((temp)->right != NULL)
      {
        (*nodePtr)->left = temp->right;
          temp->right = NULL;
      }
      return temp;
    }
    else
      {
        temp = *nodePtr;
        *height = 1;
        *nodePtr = NULL;
        return temp;
      }
}


Node *avl_Remove(Node **nodePtr, int nodeToRemove, int *height,Compare IntegerCompare)
{
  if((*nodePtr) == NULL){
    return *nodePtr;
  }
  int Result = IntegerCompare(nodeToRemove,*nodePtr);
      if(Result > 0)
      {
        avl_Remove(&((*nodePtr)->left),nodeToRemove,height,IntegerCompare);
        if(*height == 1){
          (*nodePtr)->balanceFactor++;
        }
        else
        (*nodePtr)->balanceFactor = (*nodePtr)->balanceFactor;
      }
      else if(Result < 0)
      {
        avl_Remove(&((*nodePtr)->right),nodeToRemove,height,IntegerCompare);
        if(*height == 1)
        {
          (*nodePtr)->balanceFactor--;
        }
        else
        (*nodePtr)->balanceFactor = (*nodePtr)->balanceFactor;
      }
      else
      {
            if(((*nodePtr)->left == NULL)||((*nodePtr)->right == NULL))
            {
              Node *Remove = (*nodePtr)->left ? (*nodePtr)->left :(*nodePtr)->right;
                if(Remove == NULL)
                {
                  Remove = *nodePtr;
                  *nodePtr = NULL;
                  *height = 1;
                }
                else
                {
                  *nodePtr =  Remove;
                  *height = 1;
                }
              }
            else
            {
              Node *temp = getValue(&(*nodePtr)->right,height);
              if(*height == 1)
              {
                (*nodePtr)->balanceFactor--;
                if((*nodePtr)->balanceFactor !=0)
                *height = 0;
                else
                *height = 1;
              }
              else{
                *height = 1;
              (*nodePtr)->balanceFactor = (*nodePtr)->balanceFactor;
            }
                if(temp->right != NULL)
                {
                    temp->left = (*nodePtr)->left;
                    temp->balanceFactor = (*nodePtr)->balanceFactor;
                    *nodePtr = temp;
                }
                else
                {
                  temp->right = (*nodePtr)->right;
                  temp->left = (*nodePtr)->left;
                  temp->balanceFactor = (*nodePtr)->balanceFactor;
                  *nodePtr = temp;
                }
            }
          }
    if((*nodePtr)==NULL)
    {
      return *nodePtr;
    }
    if((*nodePtr)->balanceFactor >= 2){
      avlBalanceRightTree(&(*nodePtr));
      if((*nodePtr)->balanceFactor !=0)
      *height = 0;
      else
      *height = 1;
}
    else if((*nodePtr)->balanceFactor <= -2){
      avlBalanceLeftTree(&(*nodePtr));
      if((*nodePtr)->balanceFactor !=0)
      *height = 0;
      else
      *height = 1;
    }
    else
    {
      *nodePtr = *nodePtr;
    }
    if((*nodePtr)->balanceFactor !=0)
    *height = 0;
    if((*nodePtr)->left==NULL&&(*nodePtr)->right==NULL)
    *height = 1;
    return *nodePtr;
}

Node *RemoveNode(Node **nodePtr, int nodeToRemove,Compare IntCompare)
{
  int height;
  Node *RemoveNode = avl_Remove(nodePtr,nodeToRemove, &height,IntCompare);
  return RemoveNode;
}
