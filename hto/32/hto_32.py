from typing import List, Dict
from queue import Queue
from collections import deque
import math
import itertools


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        def bfs(node: TreeNode, level: int) -> None:
            if level >= len(res):
                res.append([])
            res[level].append(node.val)
            if node.left:
                bfs(node.left, level+1)
            if node.right:
                bfs(node.right, level+1)

        res = []
        bfs(root, 0)
        return list(itertools.chain.from_iterable(res))


if __name__ == "__main__":
    node1 = TreeNode(3)
    node2 = TreeNode(9)
    node3 = TreeNode(20)
    node4 = TreeNode(15)
    node5 = TreeNode(7)
    node1.left = node2
    node1.right = node3
    node3.left = node4
    node3.right = node5
    s = Solution()
    print(s.levelOrder(node1))
