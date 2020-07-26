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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        def bfs(node: TreeNode, level: int)-> None:
            if level >= len(res):
                res.append([])
            res[level].append(node.val)
            if node.left is not None:
                bfs(node.left, level+1)
            if node.right is not None:
                bfs(node.right, level+1)
        res = []
        bfs(root, 0)
        return res