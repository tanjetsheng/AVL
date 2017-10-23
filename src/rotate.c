#include "rotate.h"
#include <stdio.h>
#include "Node.h"


Node *rotateRight(Node *node){
  Node *root;
  root = node->left;
  node->left = node->left->right;
  root ->right = node;

}

Node *rotateLeft(Node *node){
  Node *root;
  root = node->left->right;
  root ->right = node;

}
