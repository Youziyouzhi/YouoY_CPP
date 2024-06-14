#include <vector> 
#include <queue>
#include "basic.hpp"

std::vector<int> levelOrder(TreeNode *root) {
  //广度优先搜索
  std::queue<TreeNode *> queue;
  queue.push(root);
  std::vector<int> res;
  while (!queue.empty()) {
    TreeNode *tmp = queue.front();
    queue.pop();
    res.push_back(tmp->val);
    if (tmp->left != nullptr) {
      queue.push(tmp->left);
    }
    if (tmp->right != nullptr) {
      queue.push(tmp->right);
    }
  } 
  return res; 
}