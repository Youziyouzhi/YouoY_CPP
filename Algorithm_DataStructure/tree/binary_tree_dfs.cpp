#include <vector> 
#include <queue>
#include "basic.hpp"

std::vector<int> prevec;
std::vector<int> invec;
std::vector<int> postvec;

void preOrder(TreeNode *root) {
  //前序遍历
  if (root == nullptr) {
    return;
  }
  prevec.push_back(root->val);
  preOrder(root->left);
  preOrder(root->right);
}

void inOrdre(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  inOrdre(root->left);
  invec.push_back(root->val);
  inOrdre(root->right);
}

void postOrder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  postvec.push_back(root->val);   
}