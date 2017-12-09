#include "noderemove.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"
#include "avlint.h"


Node *getValue(Node **nodePtr,int *height)
{
  Node *temp;
  Node *child = (*nodePtr)->left;

  if(child != NULL)
  {
    if(child->left != NULL)
      getValue(&(*nodePtr)->left,height);
      else
      {
        if(child->right != NULL)
        {
          (*nodePtr)->left = child->right;
          (*nodePtr)->balanceFactor++;
          child->right = NULL;
          if((*nodePtr)->balanceFactor !=0)
          *height = 0;
          else
          *height = 1;
        }
        else
        {
          (*nodePtr)->left = NULL;
          (*nodePtr)->balanceFactor++;

          if((*nodePtr)->balanceFactor >= 2)
            avlBalanceRightTree(&(*nodePtr));
          else if((*nodePtr)->balanceFactor <= -2)
            avlBalanceLeftTree(&(*nodePtr));
          else{
            *nodePtr = *nodePtr;
          }
          if((*nodePtr)->balanceFactor !=0)
          *height = 0;
          else
          *height = 1;
        }
        return child;
      }
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
              else
              (*nodePtr)->balanceFactor = (*nodePtr)->balanceFactor;
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
    if((*nodePtr)->balanceFactor >= 2)
      avlBalanceRightTree(&(*nodePtr));
    else if((*nodePtr)->balanceFactor <= -2)
      avlBalanceLeftTree(&(*nodePtr));
    else
    {
      *nodePtr = *nodePtr;
    }
    if((*nodePtr)->balanceFactor !=0)
    *height = 0;
    else
    *height = 1;
    return *nodePtr;
}

Node *RemoveNode(Node **nodePtr, int nodeToRemove,Compare IntCompare)
{
  int height;
  Node *RemoveNode = avl_Remove(nodePtr,nodeToRemove, &height,IntCompare);
  return RemoveNode;
}
