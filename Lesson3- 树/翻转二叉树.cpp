#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 */
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {

//     }
// };
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归版本
TreeNode* invertTree(TreeNode* root) {  // 先序优先遍历
  if (root == NULL) {
    return NULL;
  }
  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

TreeNode* invertTree(TreeNode* root) {  // 后序优先遍历
  if (root == NULL) {
    return NULL;
  }
  invertTree(root->left);
  invertTree(root->right);
  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  return root;
}

TreeNode* invertTree(TreeNode* root) {  // 中序优先遍历
  if (root == NULL) {
    return NULL;
  }
  invertTree(root->left);
  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  invertTree(root->left);
  return root;
}

// 非递归，使用队列
TreeNode* invertTree(TreeNode* root) {  // 中序优先遍历
  if (root == NULL) {
    return NULL;
  }
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* current = q.front();
    q.pop();
    swap(current->left, current->right);
    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }
  }
  return root;
}