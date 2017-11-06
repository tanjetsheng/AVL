#include "unity.h"
#include "noderemove.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"

Node node1,node5 , node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55;

void initNode(Node *node,Node *left,Node *right,int bf){
  node->left = left;
  node->right = right;
  node->bf = bf;
}
void setUp(void)
{
  node1.data = 1;
  node5.data = 5;
  node10.data = 10;
  node15.data = 15;
  node20.data = 20;
  node25.data = 25;
  node30.data = 30;
  node35.data = 35;
  node40.data = 40;
  node45.data = 45;
  node50.data = 50;
  node55.data = 55;
}

void tearDown(void)
{
}

void test_noderemove_remove(void)
{
    Node *root = &node10;
    initNode(&node10,NULL,NULL,-1);
//    initNode(&node5,NULL,NULL,0);
    removeNode(&root,&node10);
    TEST_ASSERT_EQUAL_PTR(NULL,root);
}
