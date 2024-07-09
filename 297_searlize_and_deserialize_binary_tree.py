# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """

        def preorder_trav(root_node):
            if root_node != None:
                list_of_data.append(str(root_node.val))
                if root_node.left != None:
                    preorder_trav(root_node.left)

                if root_node.right != None:
                    preorder_trav(root_node.right)
            else:
                list_of_data.append("$")

        list_of_data = []
        preorder_trav(root)
        return ",".join(list_of_data)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """

        def make_tree():
            node_value = next(nodes)
            if node_value == "$":
                return None

            node = TreeNode(int(node_value))
            node.left = make_tree()
            node.right = make_tree()
            return node

        nodes = iter(data.split(","))
        return make_tree()


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
