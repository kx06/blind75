from typing import Optional
from collections import deque


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return node

        queue = deque([node])
        clones = {node.val: Node(node.val, [])}
        while queue:
            current_node = queue.popleft()
            current_node_clone = clones[current_node.val]

            for next_node in current_node.neighbors:
                if next_node.val not in clones:
                    clones[next_node.val] = Node(next_node.val, [])
                    queue.append(next_node)

                current_node_clone.neighbors.append(clones[next_node.val])

        return clones[node.val]
