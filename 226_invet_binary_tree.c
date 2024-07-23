#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void inorder_trav(struct TreeNode *root) {
  if (root == NULL) {
    return;
  }
  struct TreeNode *tmpn = root->left;
  root->left = root->right;
  root->right = tmpn;
  inorder_trav(root->left);
  inorder_trav(root->right);
}

struct TreeNode *invertTree(struct TreeNode *root) {
  inorder_trav(root);
  return root;
}
