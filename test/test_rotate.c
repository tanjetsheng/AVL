#include "unity.h"
#include "rotate.h"
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
{}

  /*void test_xxx(){
    initNode(&node30,NULL,NULL,3);
    testAssertNodeEqual(&node20)

  }*/
//right
/**
 *        30            10
 *       /             /  \
 *     10       ---> 5    30
 *    /  \               /
 *  5     20           20
 *
 */
 //left
 /**
  *        30            20
  *       /             /  \
  *     10       ---> 10    30
  *    /  \          /
  *  5     20      5
  *
  */
void test_rotateRight(void)
{
    Node *root;
    initNode(&node5,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node10,&node5,&node20,0);
    initNode(&node30,&node10,NULL,-2);

    root = rotateRight(&node30);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

}
