#ifndef _AVLINT_H
#define _AVLINT_H
#include "Node.h"

typedef int(*Compare)(void *data,Node *refNode);

int IntegerCompare(int data, Node *refNode);

#endif // _AVLINT_H
