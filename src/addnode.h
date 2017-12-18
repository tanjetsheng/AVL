#ifndef _ADDNODE_H
#define _ADDNODE_H
#include "Node.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "avlint.h"


#define avlAddInteger(nodePtr,newNode)  addNode(nodePtr,newNode,(Compare)IntegerCompare)
#define avlAddString(nodePtr,newNode)  addNode(nodePtr,newNode,(Compare)StringCompare)
int addNode(Node **nodePtr,Node *newNode,Compare IntegerCompare);


#endif // _ADDNODE_H
