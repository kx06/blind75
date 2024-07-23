#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool ValidBST(struct TreeNode *root, long *prev) {
  if (root->left != NULL) {
    if (ValidBST(root->left, prev) == false) {
      return false;
    }
  }
  if (*prev >= root->val) {
    return false;
  } else {
    *prev = root->val;
  }
  if (root->right != NULL) {
    if (ValidBST(root->right, prev) == false) {
      return false;
    }
  }
  return true;
}

bool isValidBST(struct TreeNode *root) {
  long max = -2147483649;
  long *prev = &max;
  return ValidBST(root, prev);
}
