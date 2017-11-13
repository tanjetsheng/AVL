#ifndef _NODEREMOVE_H
#define _NODEREMOVE_H
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"

Node *removeNode(Node **nodePtr,Node *nodeToRemove);
Node *getRightValue(Node *nodePtr);
Node *getLeftValue(Node *nodePtr);


#endif // _NODEREMOVE_H
