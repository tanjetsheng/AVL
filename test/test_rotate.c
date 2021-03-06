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
 *       /   \          /  \
 *     10     40  ---> 5    30
 *    /  \                /   \
 *  5     20            20    40
 *
 */
void test_rotateRight(void)
{
    Node *root;
    initNode(&node5,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node10,&node5,&node20,0);
    initNode(&node30,&node10,&node40,-2);

    root = rotateRight(&node30);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

}

//left
/**
---------rotateleft-----------------
*        10            30
*         \           /   \
*          30  ->    10    40
*         / \         \
*        25  40       25
*
**/


void test_rotateLeft(void)
{
    Node *root;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node30,&node25,&node40,0);
    initNode(&node10,NULL,&node30,2);

    root = rotateLeft(&node10);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
}

/**
---------rotateleftright-----------------
*        45                   45                   30
*       /  \      RL"10"    /   \      RR"45"     /   \
*      10   50  ------->  30    50  ----------> 10     45
*        \               /  \                     \    / \
*        30             10   40                   25  40 50
*       /  \              \
*      25   40             25
*
**/

void test_rotateLeftRight(void)
{
    Node *root;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node30,&node25,&node40,0);
    initNode(&node10,NULL,&node30,-2);
    initNode(&node45,&node10,&node50,-2);
    initNode(&node50,NULL,NULL,0);

    root = rotateLeftRight(&node45);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
}

/**
---------rotaterightleft-----------------
*         5                   5                   25
*       /  \      RL"40"    /   \      RR"5"     /   \
*      1   40  ------->   1     25  ----------> 5     40
*          /                    / \            /  \   /
*        25                    20 40          1   20  35
*       /  \                     /
*      20   35                  35
*
**/

void test_rotateRightLeft(void)
{
    Node *root;
    initNode(&node20,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node25,&node20,&node35,0);
    initNode(&node40,&node25,NULL,-2);
    initNode(&node5,&node1,&node40,2);
    initNode(&node1,NULL,NULL,0);

    root = rotateRightLeft(&node5);
    TEST_ASSERT_EQUAL_PTR(&node25,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(&node20,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
}

//left(balance)_2_0
/**
---------rotateleft-----------------
*        10(2)            30(-1)
*         \              /   \
*          30(0)  ->   10(1)  40(0)
*         / \            \
*      25(0) 40(0)       25(0)
*
**/


void test_rotateLeftBalance_2_0_type(void)
{
    Node *root = &node10;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node30,&node25,&node40,0);
    initNode(&node10,NULL,&node30,2);

    avlBalanceRightTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL(-1,node30.balanceFactor);
    TEST_ASSERT_EQUAL(1,node10.balanceFactor);
    TEST_ASSERT_EQUAL(0,node40.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
}

//left(balance)_2_1
/**
---------rotateleft-----------------
*        10(2)            30(0)
*       /  \              /   \
*     5(0)  30(1)  ->   10(0)  40(1)
*         / \           / \      \
*      25(0) 40(1)    5(0) 25(0)  50(0)
*             \
*              50(0)
**/


void test_rotateLeftBalance_2_1_type(void)
{
    Node *root = &node10;
    initNode(&node50,NULL,NULL,0);
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,&node50,1);
    initNode(&node30,&node25,&node40,1);
    initNode(&node10,&node5,&node30,2);
    initNode(&node5,NULL,NULL,0);

    avlBalanceRightTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);

    TEST_ASSERT_EQUAL(0,node30.balanceFactor);
    TEST_ASSERT_EQUAL(0,node10.balanceFactor);
    TEST_ASSERT_EQUAL(1,node40.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
    TEST_ASSERT_EQUAL(0,node5.balanceFactor);
    TEST_ASSERT_EQUAL(0,node50.balanceFactor);
}

//rightBalanced(_-2_0)
/**
 *        30(-2)         10(1)
 *       /              /  \
 *     10(0)     ---> 5(0)  30(-1)
 *    /  \                 /
 *  5(0) 20(0)            20(0)
 *
 */
void test_rotateRightBalanced_neg2_0(void)
{
    Node *root = &node30;
    initNode(&node5,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node10,&node5,&node20,0);
    initNode(&node30,&node10,NULL,-2);

    avlBalanceLeftTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

    TEST_ASSERT_EQUAL(0,node5.balanceFactor);
    TEST_ASSERT_EQUAL(1,node10.balanceFactor);
    TEST_ASSERT_EQUAL(-1,node30.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
}

//rightBalanced(_-2_-1)
/**
 *        30(-2)         10(0)
 *       /              /  \
 *     10(-1)     ---> 5(0)  30(0)
 *    /
 *  5(0)
 *
 */

 void test_rotateRightBalanced_neg2_neg1(void)
 {
    Node *root = &node30;
     initNode(&node5,NULL,NULL,0);
     initNode(&node10,&node5,NULL,-1);
     initNode(&node30,&node10,NULL,-2);

     avlBalanceLeftTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node10,root);
     TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
     TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
     TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
     TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
     TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
     TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

     TEST_ASSERT_EQUAL(0,node5.balanceFactor);
     TEST_ASSERT_EQUAL(0,node10.balanceFactor);
     TEST_ASSERT_EQUAL(0,node30.balanceFactor);

}

/**
---------rotate leftright When grandchild 0-----------------
*          45(-2)               45(-2)                      30(0)
*         /  \      RL"10"     /     \      RR"45"         /      \
*      10(1) 50(0)  -------> 30(-1)  50(0)  ---------->  10(0)   45(0)
*     /    \                /  \                        /   \     /   \
*   20(0) 30(0)           10(0) 40(0)                20(0) 25(0) 40(0) 50(0)
*        /   \           /  \
*      25(0) 40(0)    20(0)  25(0)
*
**/

void test_rotateLeftRightBalanced_grand_0(void)
{
    Node *root = &node45;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node30,&node25,&node40,0);
    initNode(&node10,&node20,&node30,1);
    initNode(&node45,&node10,&node50,-2);
    initNode(&node50,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);

    avlBalanceLeftTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node20,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);

    TEST_ASSERT_EQUAL(0,node10.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
    TEST_ASSERT_EQUAL(0,node30.balanceFactor);
    TEST_ASSERT_EQUAL(0,node45.balanceFactor);
    TEST_ASSERT_EQUAL(0,node40.balanceFactor);
}

/**
---------rotate leftright When grandchild -1-----------------
*          45(-2)               45(-2)                      30(0)
*         /  \      RL"10"     /     \      RR"45"         /      \
*      10(1) 50(0)  -------> 30(-2)  50(0)  ---------->  10(0)   45(1)
*     /    \                /                           /   \        \
*   20(0) 30(-1)         10(0)                      20(0) 25(0)      50(0)
*        /              /  \
*      25(0)        20(0)  25(0)
*
**/

void test_rotateLeftRightBalanced_grand_neg1(void)
{
    Node *root = &node45;
    initNode(&node25,NULL,NULL,0);
    initNode(&node30,&node25,NULL,-1);
    initNode(&node10,&node20,&node30,1);
    initNode(&node45,&node10,&node50,-2);
    initNode(&node50,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);

    avlBalanceLeftTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node20,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node45.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);

    TEST_ASSERT_EQUAL(0,node10.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
    TEST_ASSERT_EQUAL(0,node30.balanceFactor);
    TEST_ASSERT_EQUAL(1,node45.balanceFactor);
}

/**
---------rotate leftright When grandchild 1-----------------
*          45(-2)               45(-2)                      30(0)
*         /  \      RL"10"     /     \      RR"45"         /      \
*      10(1) 50(0)  -------> 30(-1)  50(0)  ---------->  10(-1)   45(0)
*     /    \                /  \                        /        /   \
*   20(0) 30(1)           10(1) 40(0)                20(0)     40(0) 50(0)
*           \           /
*           40(0)    20(0)
*
**/

void test_rotateLeftRightBalanced_grand_1(void)
{
    Node *root = &node45;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node30,NULL,&node40,1);
    initNode(&node10,&node20,&node30,1);
    initNode(&node45,&node10,&node50,-2);
    initNode(&node50,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);

    avlBalanceLeftTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(&node20,node10.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);

    TEST_ASSERT_EQUAL(-1,node10.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
    TEST_ASSERT_EQUAL(0,node30.balanceFactor);
    TEST_ASSERT_EQUAL(0,node45.balanceFactor);
    TEST_ASSERT_EQUAL(0,node40.balanceFactor);
}

/**
---------rotaterightleft_Grand_0-----------------
*         5(2)                    5(2)                     25(0)
*       /  \        RL"40"      /   \          RR"5"      /     \
*     1(0)  40(-1)  ------->  1(0)   25(1)  ----------> 5(0)     40(0)
*          /   \                     /   \              /  \      /   \
*        25(0)  50(0)             20(0) 40(1)        1(0) 20(0) 35(0) 50(0)
*       /  \                           /   \
*     20(0) 35(0)                    35(0) 50(0)
*
**/

void test_rotateRightLeftBalanced_grand_0(void)
{
    Node *root = &node5;
    initNode(&node20,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node50,NULL,NULL,0);
    initNode(&node25,&node20,&node35,0);
    initNode(&node40,&node25,&node50,-1);
    initNode(&node5,&node1,&node40,2);
    initNode(&node1,NULL,NULL,0);

    avlBalanceRightTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node25,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(&node20,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);

    TEST_ASSERT_EQUAL(0,node1.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
    TEST_ASSERT_EQUAL(0,node5.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
    TEST_ASSERT_EQUAL(0,node40.balanceFactor);
    TEST_ASSERT_EQUAL(0,node35.balanceFactor);
    TEST_ASSERT_EQUAL(0,node50.balanceFactor);
}

/**
---------rotaterightleft_Grand_1-----------------
*         5(2)                    5(2)                     25(0)
*       /  \        RL"40"      /   \          RR"5"      /     \
*     1(0)  40(-1)  ------->  1(0)   25(2)  ----------> 5(-1)   40(0)
*          /   \                         \              /         /   \
*        25(1)  50(0)                   40(0)        1(0)       35(0) 50(0)
*          \                           /   \
*           35(0)                    35(0) 50(0)
*
**/

void test_rotateRightLeftBalanced_grand_1(void)
{
    Node *root = &node5;
    initNode(&node35,NULL,NULL,0);
    initNode(&node50,NULL,NULL,0);
    initNode(&node25,NULL,&node35,1);
    initNode(&node40,&node25,&node50,-1);
    initNode(&node5,&node1,&node40,2);
    initNode(&node1,NULL,NULL,0);

    avlBalanceRightTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node25,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);

    TEST_ASSERT_EQUAL(0,node1.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
    TEST_ASSERT_EQUAL(-1,node5.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
    TEST_ASSERT_EQUAL(0,node40.balanceFactor);
    TEST_ASSERT_EQUAL(0,node35.balanceFactor);
    TEST_ASSERT_EQUAL(0,node50.balanceFactor);
}

/**
---------rotaterightleft_Grand_-1-----------------
*         5(2)                    5(2)                     25(0)
*       /  \        RL"40"      /   \          RR"5"      /     \
*     1(0)  40(-1)  ------->  1(0)   25(1)  ----------> 5(0)     40(1)
*          /   \                     /   \              /  \         \
*       25(-1) 50(0)             20(0) 40(1)        1(0) 20(0)       50(0)
*       /                                 \
*     20(0)                              50(0)
*
**/

void test_rotateRightLeftBalanced_grand_neg1(void)
{
    Node *root = &node5;
    initNode(&node20,NULL,NULL,0);
    initNode(&node50,NULL,NULL,0);
    initNode(&node25,&node20,NULL,-1);
    initNode(&node40,&node25,&node50,-1);
    initNode(&node5,&node1,&node40,2);
    initNode(&node1,NULL,NULL,0);

    avlBalanceRightTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node25,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(&node20,node5.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);

    TEST_ASSERT_EQUAL(0,node1.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
    TEST_ASSERT_EQUAL(0,node5.balanceFactor);
    TEST_ASSERT_EQUAL(0,node25.balanceFactor);
    TEST_ASSERT_EQUAL(1,node40.balanceFactor);
    TEST_ASSERT_EQUAL(0,node35.balanceFactor);
    TEST_ASSERT_EQUAL(0,node50.balanceFactor);
}
