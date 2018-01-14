#include "unity.h"
#include "addnode.h"
#include "Node.h"
#include "rotate.h"
#include "nodeverifier.h"
#include "avlint.h"
#include "noderemove.h"

Node node1,node5 , node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55,node60,node65,node70,node75,node80,node85,node90,node95,node100;
StringNode nodeAli,nodeBaba,nodeFafa,nodeAndy,nodeRex,nodeWeiAik,nodeDanny,nodeZheHao,nodeJstan,nodeThengChun;

void initNode(Node *node,Node *left,Node *right,int balanceFactor){
  node->left = left;
  node->right = right;
  node->balanceFactor = balanceFactor;
}

void initStringNode(StringNode *node,StringNode *left,StringNode *right,int balanceFactor){
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
  nodeFafa.data="Fafa";
  nodeAndy.data="Andy";
  nodeRex.data="Rex";
  nodeWeiAik.data="WeiAik";
  nodeDanny.data="Danny";
  nodeZheHao.data="ZheHao";
  nodeJstan.data="Jstan";
  nodeThengChun.data="ThengChun";
}

void tearDown(void)
{
}

void test_compareString(void)
{
    int a =  StringCompare("Ali",&nodeAli);
    int b =  StringCompare("Fa",&nodeAli);
    int c =  StringCompare("Dodo",&nodeFafa);
    int d = StringCompare("Fafa",&nodeAli);
    TEST_ASSERT_EQUAL(a,0);
    TEST_ASSERT_EQUAL(b,1);
    TEST_ASSERT_EQUAL(c,-1);
    TEST_ASSERT_EQUAL(d,1);

}

void test_initString(void){
  initStringNode(&nodeAli,NULL,NULL,0);
  TEST_ASSERT_EQUAL_PTR(NULL,nodeAli.left);
  TEST_ASSERT_EQUAL_PTR(NULL,nodeAli.right);
}

void test_addString(void){
  initStringNode(&nodeJstan,NULL,NULL,0);
  avlAddString(&nodeJstan,&nodeThengChun);
  TEST_ASSERT_EQUAL_PTR(&nodeThengChun,nodeJstan.left);
  TEST_ASSERT_EQUAL_PTR(NULL,nodeJstan.right);

}

void test_noderemove_removeString(void)
{
    Node *root = &nodeDanny;
    initStringNode(&nodeDanny,&nodeWeiAik,&nodeAli,0);
    initStringNode(&nodeAli,NULL,NULL,0);
    initStringNode(&nodeWeiAik,NULL,NULL,0);
    avlRemoveString(&root,"WeiAik");
    TEST_ASSERT_EQUAL_PTR(NULL,nodeDanny.left);
    TEST_ASSERT_EQUAL_PTR(&nodeAli,nodeDanny.right);


}

void test_noderemove_removeString_with_4_node(void)
{
    Node *root = &nodeDanny;
    initStringNode(&nodeDanny,&nodeWeiAik,&nodeAli,-1);
    initStringNode(&nodeAli,NULL,NULL,0);
    initStringNode(&nodeWeiAik,NULL,&nodeRex,1);
    initStringNode(&nodeRex,NULL,NULL,0);
    avlRemoveString(&root,"Rex");
    TEST_ASSERT_EQUAL_PTR(&nodeWeiAik,nodeDanny.left);
    TEST_ASSERT_EQUAL_PTR(&nodeAli,nodeDanny.right);
    TEST_ASSERT_EQUAL_PTR(NULL,nodeWeiAik.left);
    TEST_ASSERT_EQUAL_PTR(NULL,nodeWeiAik.right);


}
