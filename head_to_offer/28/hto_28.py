from typing import List, Dict
from queue import Queue
from collections import deque
import math


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: 
            return True
        queue = deque()
        queue.append(root.left)
        queue.append(root.right)
        while queue:
            first = queue.popleft()
            second = queue.popleft()
            if not first and not second: 
                continue
            if not first or not second or first.val != second.val: 
                return False
            queue.append(first.left)
            queue.append(second.right)
            queue.append(first.right)
            queue.append(second.left)
        return True


if __name__ == "__main__":
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(2)
    node4 = TreeNode(3)
    node5 = TreeNode(3)
    node1.left = node2
    node1.right = node3
    node2.left = node4
    node3.right = node5
    s = Solution()
    print(s.isSymmetric(node1))
