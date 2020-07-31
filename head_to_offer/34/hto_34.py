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
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root: 
            return []
        res, tmp = [], []
        self.dfs(root, sum, res, tmp)
        return res
        
    def dfs(self, node: TreeNode, num: int, res: List, tmp: List) -> None:
        if not node:
            return
        tmp.append(node.val)
        if not node.left and not node.right and num == node.val:
            res.append(tmp[:])
            tmp.pop()
            return
        self.dfs(node.left,  num - node.val, res, tmp)
        self.dfs(node.right, num - node.val, res, tmp)
        tmp.pop()



if __name__ == "__main__":
    node1 = TreeNode(5)
    node2 = TreeNode(4)
    node3 = TreeNode(8)
    node4 = TreeNode(11)
    node5 = TreeNode(13)
    node6 = TreeNode(4)
    node7 = TreeNode(7)
    node8 = TreeNode(2)
    node9 = TreeNode(5)
    node10 = TreeNode(1)
    node1.left = node2
    node1.right = node3
    node2.left = node4
    node3.left = node5
    node3.right = node6
    node4.left = node7
    node4.right = node8
    node6.left = node9
    node6.right = node10
    s = Solution()
    print(s.pathSum(node1, 22))
