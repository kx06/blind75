# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        lst = []

        def inorder(root):
            if root.left is not None:
                inorder(root.left)
            lst.append(root.val)
            if root.right is not None:
                inorder(root.right)

        inorder(root)
        return lst[k - 1]