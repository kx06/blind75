#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool inorder(struct TreeNode *a, struct TreeNode *b) {
  if (a == NULL ^ b == NULL) {
    return false;
  } else {
    if (a == NULL & a == b) {
      return true;
    }
    if (a->val == b->val) {
      if (inorder(a->left, b->left) == false) {
        return false;
      }
      if (inorder(a->right, b->right) == false) {
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  return (inorder(p, q));
}
