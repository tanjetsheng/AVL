#include "rotate.h"
#include <stdio.h>
#include "Node.h"

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

Node *rotateLeftright(Node *node){
//  Node *root;
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
