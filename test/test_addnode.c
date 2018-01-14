#include "unity.h"
#include "addnode.h"
#include "Node.h"
#include "rotate.h"
#include "nodeverifier.h"
#include "avlint.h"

Node node1,node5 , node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55,node60,node65,node70,node75,node80,node85,node90,node95,node100;
StringNode nodeAli,nodeBaba,nodeAfa;

void initNode(Node *node,Node *left,Node *right,int balanceFactor){
  node->left = left;
  node->right = right;
  node->balanceFactor = balanceFactor;
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

  nodeAli.data="Ali";
  nodeBaba.data="Baba";
  nodeAfa.data="Afa";
}

void tearDown(void)
{
}

void test_adding_into_a_NULL(void){
      Node *root = NULL;
      avlAddInteger(&root,&node20);

      TEST_ASSERT_EQUAL_PTR(&node20,root);
      TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
}

void test_creating_an_AVL_tree(void){
  Node *root = NULL;
  avlAddInteger(&root,&node20);
  avlAddInteger(&root,&node10);
  avlAddInteger(&root,&node30);
  avlAddInteger(&root,&node5);
  avlAddInteger(&root,&node15);

  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_NODE(&node10,&node30,-1,&node20);
  TEST_ASSERT_EQUAL_NODE(&node5,&node15,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
}

void test_addnode_addNoderight(void)
{
      Node *root = &node25;
      initNode(&node20,NULL,NULL,0);
      initNode(&node35,NULL,NULL,0);
      initNode(&node25,&node20,&node35,0);

      avlAddInteger(&root,&node40);
      TEST_ASSERT_EQUAL_PTR(&node25,root);
      TEST_ASSERT_EQUAL_PTR(&node20,node25.left);
      TEST_ASSERT_EQUAL_PTR(&node35,node25.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
      TEST_ASSERT_EQUAL_PTR(&node40,node35.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
      TEST_ASSERT_EQUAL(1,node25.balanceFactor);
}



void test_addnode_addNodeleft(void)
{
      Node *root = &node25;
      initNode(&node20,NULL,NULL,0);
      initNode(&node35,NULL,NULL,0);
      initNode(&node25,&node20,&node35,0);

      avlAddInteger(&root,&node10);
      TEST_ASSERT_EQUAL_PTR(&node25,root);
      TEST_ASSERT_EQUAL_PTR(&node20,node25.left);
      TEST_ASSERT_EQUAL_PTR(&node35,node25.right);
      TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
}

/*          20                           20
/          /   \                       /     \
/        10     25      --->        10        25
/      /                           /  \
/    5                           5     15
*/
void test_addnode_addNodelef_with_not_changing_the_root_balance_factor(void)
{
      Node *root = &node20;
      initNode(&node20,&node10,&node25,-1);
      initNode(&node10,&node5,NULL,-1);
      initNode(&node25,NULL,NULL,0);
      initNode(&node5,NULL,NULL,0);

      avlAddInteger(&root,&node15);
      TEST_ASSERT_EQUAL_PTR(&node20,root);
      TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
      TEST_ASSERT_EQUAL_PTR(&node25,node20.right);
      TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
      TEST_ASSERT_EQUAL_PTR(&node15,node10.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node15.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node15.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
      TEST_ASSERT_EQUAL(-1,node20.balanceFactor);
      TEST_ASSERT_EQUAL(0,node10.balanceFactor);
      TEST_ASSERT_EQUAL(0,node5.balanceFactor);
      TEST_ASSERT_EQUAL(0,node15.balanceFactor);
}

/*                20                 20                     25
/                   \                  \                  /     \
/                    25       -->       25    -->       20        30
/                                        \
/                                         30
*/

void test_addnode_rotate(void)
{
      Node *root = &node20;
      initNode(&node20,NULL,&node25,1);
      initNode(&node25,NULL,NULL,0);

      avlAddInteger(&root,&node30);
      TEST_ASSERT_EQUAL_NODE(&node20,&node30,0,&node25);

}
