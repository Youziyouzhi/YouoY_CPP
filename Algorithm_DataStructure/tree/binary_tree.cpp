#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "basic.hpp"

void test1();

int main() {
  return 0;
}

void test1() {
  //初始化二叉树
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);

  //构建节点之间的（指针）

  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  
  //插入节点
  TreeNode *p = new TreeNode(0);
  n1->left = p;
  p->left = n2;

  //删除节点
  TreeNode *tmp = n1->left;
  n1->left = n2;
  delete tmp;
}