#ifndef _NODEREMOVE_H
#define _NODEREMOVE_H
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"
#include "avlint.h"

#define avlRemoveInteger(rootPtr,nodeToRemove) RemoveNode(rootPtr,nodeToRemove,(Compare) IntegerCompare)
#define avlRemoveString(rootPtr,nodeToRemove) RemoveNode(rootPtr,nodeToRemove,(Compare) StringCompare)
Node *RemoveNode(Node **nodePtr, int nodeToRemove,Compare IntegerCompare);
Node *avl_Remove(Node **nodePtr, int nodeToRemove, int *height,Compare IntegerCompare);
Node *getValue(Node **nodePtr,int *height);


#endif // _NODEREMOVE_H
