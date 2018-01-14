#include "avlint.h"

int IntegerCompare(int data, Node *refNode)       //compare function for int
{

  if (data < refNode->data)
  {
    return 1;
  }
  else if(data > refNode->data)
  {
    return -1;
  }
  else
    return 0;
}

int StringCompare(char *data,StringNode *refNode){    //compare function for
  int result = strcmp(data,refNode->data);            //string
  if(result>0)
  return 1;
  else if(result<0)
  return -1;
  else
  return 0;
}
