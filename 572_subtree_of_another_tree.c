#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool is_equal(struct TreeNode *root, struct TreeNode *subRoot) {
  if (root == NULL && subRoot == NULL) {
    return true;
  }
  if (root == NULL ^ subRoot == NULL) {
    return false;
  }
  if (root->val == subRoot->val) {
    return is_equal(root->left, subRoot->left) &&
           is_equal(root->right, subRoot->right);
  } else {
    return false;
  }
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot) {
  if (is_equal(root, subRoot)) {
    return true;
  } else {
    if (root != NULL) {
      if (isSubtree(root->left, subRoot)) {
        return true;
      }
      if (isSubtree(root->right, subRoot)) {
        return true;
      }
    }
  }
  return false;
}
