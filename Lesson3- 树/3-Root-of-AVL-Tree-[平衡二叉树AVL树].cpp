#include <iostream>
using namespace std;
struct AVLNode {
  int data;
  AVLNode *left, *right;
};
AVLNode* rotateLeft(AVLNode* root) {
  AVLNode* t = root->left;
  root->left = t->right;
  t->right = root;
  return t;
}
AVLNode* rotateRight(AVLNode* root) {
  AVLNode* t = root->right;
  root->right = t->left;
  t->left = root;
  return t;
}
AVLNode* rotateLeftRight(AVLNode* root) {
  root->left = rotateRight(root->left);
  return rotateLeft(root);
}
AVLNode* rotateRightLeft(AVLNode* root) {
  root->right = rotateLeft(root->right);
  return rotateRight(root);
}
int getHeight(AVLNode* root) {
  if (root == NULL)
    return 0;
  return max(getHeight(root->left), getHeight(root->right)) + 1;
}
AVLNode* insert(AVLNode* root, int val) {
  if (root == NULL) {
    root = new AVLNode();
    root->data = val;
    root->left = root->right = NULL;
  } else if (val < root->data) {
    root->left = insert(root->left, val);
    if (getHeight(root->left) - getHeight(root->right) > 1) {
      root = val < root->left->data ? rotateLeft(root) : rotateLeftRight(root);
    }
  } else if (val > root->data) {
    root->right = insert(root->right, val);
    if (getHeight(root->right) - getHeight(root->left) > 1) {
      root = val > root->right->data ? rotateRight(root) : rotateRightLeft(root);
    }
  }
  // val == root->data 无须插入
  return root;
}
int main() {
  int n, val;
  scanf("%d", &n);
  AVLNode* root = NULL;
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    root = insert(root, val);
  }
  printf("%d", root->data);
  return 0;
}