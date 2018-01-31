#include "unity.h"
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
Node node120,node150,node200,node250;

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
  node120.data = 120;
  node150.data = 150;
  node200.data = 200;
  node250.data = 250;
}
void tearDown(void)
{
}

void test_addingandremove(void){
  Node *root = NULL;

  avlAddInteger(&root,&node5);
  avlAddInteger(&root,&node25);
  avlAddInteger(&root,&node40);
  avlAddInteger(&root,&node50);
  avlAddInteger(&root,&node60);
  avlAddInteger(&root,&node65);
  avlAddInteger(&root,&node75);
  avlAddInteger(&root,&node80);
  avlAddInteger(&root,&node90);
  avlAddInteger(&root,&node100);
  avlAddInteger(&root,&node120);
  avlAddInteger(&root,&node150);
  avlAddInteger(&root,&node200);
  avlAddInteger(&root,&node250);

/*  avlRemoveInteger(&root,25);
  avlRemoveInteger(&root,65);
  avlRemoveInteger(&root,50);
  avlRemoveInteger(&root,100);
  avlRemoveInteger(&root,80);
  TEST_ASSERT_EQUAL_NODE(&node60,&node150,0,&node90);
*/

  avlRemoveInteger(&root,65);
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,-1,&node75);
  TEST_ASSERT_EQUAL_NODE(&node25,&node75,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node50,&node150,0,&node80);
  avlRemoveInteger(&root,150);
  TEST_ASSERT_EQUAL_NODE(&node50,&node200,0,&node80);
  TEST_ASSERT_EQUAL_NODE(&node100,&node250,-1,&node200);
  avlRemoveInteger(&root,25);
  TEST_ASSERT_EQUAL_NODE(&node40,&node75,0,&node50);
  avlRemoveInteger(&root,100);
  avlRemoveInteger(&root,80);
  TEST_ASSERT_EQUAL_NODE(&node50,&node200,-1,&node90);


}
