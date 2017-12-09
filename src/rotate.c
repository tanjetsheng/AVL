#include "rotate.h"
#include <stdio.h>
#include "Node.h"



/*      before                   |  action |          after
*   Node  |  childNode |  grand  |         | Node  |  childNode |  grand
*     +2  |     +1     |    x    |  L      |  0    |    0       |    x
*     +2  |     0      |    x    |  L      |  1    |   -1       |    x
*     +2  |     -1     |    -1   |  RL     |  0    |    1       |    0
*     +2  |     -1     |    0    |  RL     |  0    |    0       |    0
*     +2  |     -1     |    +1   |  RL     |  -1   |    0       |    0
*     -2  |     -1     |    x    |  R      |  0    |    0       |    X
*     -2  |     0      |    x    |  R      |  -1   |    1       |    X
*     -2  |     +1     |    +1   |  LR     |  0    |    -1      |    0
*     -2  |     +1     |    0    |  LR     |  0    |    0       |    0
*     -2  |     +1     |    -1   |  LR     |  1    |    0       |    0

*/
Node *root;
Node *rotateRight(Node *node){
  root = node->left;
  node->left = node->left->right;
  root ->right = node;
  return root;
}

Node *rotateLeft(Node *node){
//  Node *root;

  root = node->right;
  node->right = root->left;
  root->left = node;
  return root;
}

Node *rotateLeftRight(Node *node){
//  Node *root;
  Node *grandChild = node->left->right;
  node->left = rotateLeft(node->left);
  root = rotateRight(node);
  return root;
}

Node *rotateRightLeft(Node *node){
  //Node *root;
  node->right = rotateRight(node->right);
  root = rotateLeft(node);
  return root;
}

int avlBalanceLeftTree(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandchild = node->left->right;
  if((bf = child->balanceFactor)==1){
    if((bf = grandchild->balanceFactor)==1){
      node->balanceFactor = 0;
      child->balanceFactor = -1;
      grandchild->balanceFactor = 0;
                                            }
    else if((bf = grandchild->balanceFactor)==0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                }
    else if((bf = grandchild->balanceFactor)==-1){
      node->balanceFactor = 1;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                  }
     *rootPtr = rotateLeftRight(*rootPtr);
      return 0;
                                     }
  else if((bf = child->balanceFactor)==0){
    node->balanceFactor = -1;
    child->balanceFactor = 1;
                                          }
  else if((bf = child->balanceFactor)==-1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
  }
    *rootPtr = rotateRight(*rootPtr);
     return 0;
}

int avlBalanceRightTree(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandchild = node->right->left;
  if((bf = child->balanceFactor)==-1){
    if((bf = grandchild->balanceFactor)==-1){
      node->balanceFactor = 0;
      child->balanceFactor = 1;
      grandchild->balanceFactor = 0;
                                            }
    else if((bf = grandchild->balanceFactor)==0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                }
    else if((bf = grandchild->balanceFactor)==1){
      node->balanceFactor = -1;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                }
      *rootPtr = rotateRightLeft(*rootPtr);
       return 0;
                                    }

  else if((bf = child->balanceFactor)==0){
    node->balanceFactor = 1;
    child->balanceFactor -= 1;
                                          }
  else if((bf = child->balanceFactor)==1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
                                          }
    *rootPtr = rotateLeft(*rootPtr);
     return 0;
}
