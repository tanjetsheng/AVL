#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H
#include "Node.h"

#define TEST_ASSERT_EQUAL_NODE(left,right,balanceFactor,node) \
                          testAssertEqualNode(left,right,balanceFactor,node,__LINE__)

void testAssertEqualNode(Node *left, Node *right, int balanceFactor, Node *node,int lineNo);
#endif // _NODEVERIFIER_H
