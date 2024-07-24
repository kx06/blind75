class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def preorder(root):
            if root.left and root.right:
                return 1 + max(preorder(root.left), preorder(root.right))
            if root.left:
                return 1 + preorder(root.left)
            if root.right:
                return 1 + preorder(root.right)
            return 0

        if not root:
            return 0
        return preorder(root) + 1
