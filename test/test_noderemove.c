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
    initNode(&node10,NULL,NULL,0);
    removeNode(&root,&node10);
    TEST_ASSERT_EQUAL_PTR(NULL,root);
}
/*
          20                      20
        /   \                   /   \
      10    30   -->          5     30
            /
          15
*/
void test_noderemovsdsadsadsad(void)
{
    Node *root = &node20;
    initNode(&node20,&node10,&node30,-1);
    initNode(&node10,NULL,NULL,0);
    initNode(&node15,NULL,NULL,0);
    initNode(&node30,&node15,NULL,-1);
    removeNode(&root,&node20);
    TEST_ASSERT_EQUAL_PTR(&node10,node15.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node15.right);
}

/*
          20                      20
        /   \                   /   \
      10    30   -->          5     30
    /
  5
*/
void test_noderemove_remove_with_right_value_is_NULL(void)
{
    Node *root = &node20;
    initNode(&node20,&node10,&node30,-1);
    initNode(&node10,&node5,NULL,-1);
    initNode(&node5,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    removeNode(&root,&node10);
    TEST_ASSERT_EQUAL_PTR(&node5,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
}

/*
          20                      20
        /   \                   /   \
      10    30   -->          15     30
    /   \                     /
  5      15                 5
*/
void test_noderemove_remove_replace_with_right_value(void)
{
    Node *root = &node20;
    initNode(&node20,&node10,&node30,-1);
    initNode(&node10,&node5,&node15,0);
    initNode(&node5,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node15,NULL,NULL,0);
    removeNode(&root,&node10);
    TEST_ASSERT_EQUAL_PTR(&node15,node20.left);
    TEST_ASSERT_EQUAL_PTR(&node5,node15.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node15.right);

}

/*
          25                      25
        /   \                   /   \
      10    30   -->          15     30
    /   \     \              /  \     \
  5      20    35          5    20     35
        /
      15
*/
void test_noderemove_remove_replace_with_right_value2(void)
{
    Node *root = &node25;
    initNode(&node25,&node10,&node30,-1);
    initNode(&node10,&node5,&node20,1);
    initNode(&node5,NULL,NULL,0);
    initNode(&node30,NULL,&node35,1);
    initNode(&node20,&node15,NULL,-1);
    initNode(&node15,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    removeNode(&root,&node10);
    TEST_ASSERT_EQUAL_PTR(&node15,node25.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node15.left);
    TEST_ASSERT_EQUAL_PTR(&node20,node15.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node35,node30.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.right);

}
