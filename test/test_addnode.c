#include "unity.h"
#include "addnode.h"
#include "Node.h"

Node node1,node5 , node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55;

void initNode(Node *node,Node *left,Node *right,int bf){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
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

void test_addnode_addNode(void)
{

      Node *root;
      initNode(&node20,NULL,NULL,0);
      initNode(&node35,NULL,NULL,0);
      initNode(&node25,&node20,&node35,0);

      addNode(&node25,&node40);
      TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
      TEST_ASSERT_EQUAL_PTR(&node40,node35.right);


}
