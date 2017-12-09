#include "unity.h"
#include "noderemove.h"
#include "stdio.h"
#include "stdlib.h"
#include "rotate.h"
#include "addnode.h"
#include "nodeverifier.h"
#include "avlint.h"

Node node1,node5 , node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55,node60,node65,node70,node75,node80,node85,node90,node95,node100;

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
  node60.data = 60;
  node65.data = 65;
  node70.data = 70;
  node75.data = 75;
  node80.data = 80;
  node85.data = 85;
  node90.data = 90;
  node95.data = 95;
  node100.data = 100;
}

void tearDown(void)
{
}






void test_noderemove_remove(void)
{
    Node *root = &node10;
    initNode(&node10,NULL,NULL,0);
    avlRemoveInteger(&root,10);
    TEST_ASSERT_EQUAL_PTR(NULL,root);
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
    avlRemoveInteger(&root,10);
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
    avlRemoveInteger(&root,10);
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
    avlRemoveInteger(&root,10);
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

/**
---------------------------------remove 50------------------------------
*       40(-1)                            40 (-2)                                  30 (0)
*       / \          remove 50          /                 rotate right           /  \
*   30 (-1) 50(0)   --------------->   30(-1)            ------------>         20    40 (0)
*   /                                 /
*  20                               20
*
**/
void test_RemoveNode_after_remove_rotate_right(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node30,&node20,NULL,-1);
    initNode(&node40,&node30,&node50,-1);

    Node *root = &node40;
    avlRemoveInteger(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
}

/**
---------------------------------remove 50------------------------------
*       40(-1)                            40 (-2)                                  30 (1)
*       / \          remove 50          /                 rotate right           /  \
*   30 (0) 50(0)   --------------->   30(0)            ------------>          20     40 (-1)
*   / \                               / \                                            /
*  20  35                           20  35                                          35
*
**/
void test_RemoveNode_after_remove_rotate_right_condition2(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node30,&node20,&node35,0);
    initNode(&node40,&node30,&node50,-1);

    Node *root = &node40;
    avlRemoveInteger(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,1,&node30);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
    TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
}

/**
---------------------------------remove 100       &           rotateLeftRight--------------------------------
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotateleftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (-1) 50  90 (0)
*      / \     \                            / \                                          /    / \
*    45  60 (1) 100(0)                    45  60 (1)                                   45   70   95
*         \                                     \
*        70                                      70
*
**/
void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition1_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node95,NULL,&node100,1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,NULL,&node70,1);

     Node *root = &node90;
     avlRemoveInteger(&root,100);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);
}

/*          30(1)                           40
          /   \                            /  \
      20(-1)  50(-1)       -->       (-1)20   50
      /       / \                       /    /  \
    15    (1)40  60                    15   45   60
             \
             45
*/
void test_remove_and_replace_with_bottom_right(void){
      initNode(&node30,&node20,&node50,1);
      initNode(&node20,&node15,NULL,-1);
      initNode(&node50,&node40,&node60,-1);
      initNode(&node40,NULL,&node45,1);
      initNode(&node60,NULL,NULL,0);
      initNode(&node15,NULL,NULL,0);
      initNode(&node45,NULL,NULL,0);

      Node *root = &node30;
      avlRemoveInteger(&root,30);
      TEST_ASSERT_EQUAL_PTR(&node40,root);
      TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node40);
      TEST_ASSERT_EQUAL_NODE(&node15,NULL,-1,&node20);
      TEST_ASSERT_EQUAL_NODE(&node45,&node60,0,&node50);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15);

}

/*
       (1)20                      30
        /   \                   /   \
      10    30(1)   -->       10     35
              \
              35
*/
void test_noderemove_remove_with_right_value_is_NULL2(void)
{
    Node *root = &node20;
    initNode(&node20,&node10,&node30,1);
    initNode(&node10,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node30,NULL,&node35,1);
    avlRemoveInteger(&root,20);
    TEST_ASSERT_EQUAL_PTR(&node35,node30.right);
    TEST_ASSERT_EQUAL_NODE(&node10,&node35,0,&node30);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
}

/*void test_noderemove_remove_with_right_value_is_NULL3(void){
  Node *root = &node20;
  initNode(&node20,NULL,NULL,0);
  removeNode(&root,&node20);
  TEST_ASSERT_EQUAL_PTR(NULL,root);

}

/*

          20                      25
        /   \                   /   \
      10    30      -->       10     30
     /      / \               /       \
    5      25  35            5         35


*/
void test_noderemove_remove_with_right_value_is_NULL4(void)
{
    Node *root = &node20;

    initNode(&node20,&node10,&node30,0);
    initNode(&node10,&node5,NULL,-1);
    initNode(&node35,NULL,NULL,0);
    initNode(&node25,NULL,NULL,0);
    initNode(&node30,&node25,&node35,0);
    avlRemoveInteger(&root,20);
    TEST_ASSERT_EQUAL_NODE(&node5,NULL,-1,&node10);
    TEST_ASSERT_EQUAL_NODE(&node10,&node30,0,&node25);
    TEST_ASSERT_EQUAL_NODE(NULL,&node35,1,&node30);
}

/**
---------------------------------------remove ----------------------------------------
*
*
*               40(-1)      ---------->         30
*              /     \                          / \
*            20(1)   50(1)                    20    50
*           / \        \                     /    /  \
*         10   30(1)   55                   10  35   55
*               \
*               35
**/
void test_noderemove_remove_with_right_value_is_NULL5(void)
{
    Node *root = &node40;

    initNode(&node40,&node20,&node50,-1);
    initNode(&node20,&node10,&node30,1);
    initNode(&node50,NULL,&node55,1);
    initNode(&node30,NULL,&node35,1);
    initNode(&node10,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node55,NULL,NULL,0);
    avlRemoveInteger(&root,40);
    TEST_ASSERT_EQUAL(&node20,node30.left);
    TEST_ASSERT_EQUAL(&node10,node20.left);
    TEST_ASSERT_EQUAL(&node35,node50.left);
    TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
    TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
    TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}


/**
---------------------------------------remove 60----------------------------------------
*                  60                           60 (0)
*                /    \       remove 40        /   \
*               40      90    ---------->     30    90(-1)
*              /  \    /   \                 / \   /  \
*            20   50  75   100             20  50  75  100
*           / \    \   \                   /   / \   \
*         10   30   55  80               10   35  55  80
*               \
*               35
**/
void test_remove_given_Avl_tree_remove_60_test2(void){

  Node *root = &node60;
  initNode(&node60,&node40,&node90,-1);
  initNode(&node40,&node20,&node50,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node50,NULL,&node55,1);
  initNode(&node75,NULL,&node80,1);
  initNode(&node100,NULL,NULL,0);
  initNode(&node30,NULL,&node35,1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);

  avlRemoveInteger(&root,40);
  TEST_ASSERT_EQUAL_NODE(&node30,&node90,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node75,&node100,-1,&node90);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
}
