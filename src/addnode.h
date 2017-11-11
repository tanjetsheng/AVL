#ifndef _ADDNODE_H
#define _ADDNODE_H
#include "Node.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
int addNode(Node **nodePtr,Node *newNode);
int avlBalanceLeftTree(Node **rootPtr);
int avlBalanceRightTree(Node **rootPtr);
Node *addNodeBalance(Node **nodePtr,Node *newNode);

#endif // _ADDNODE_H
