from collections import deque
from typing import List, Dict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        res = float("-inf")
        def dfs(node):
            nonlocal res
            if not node:
                return 0
            left = max(0, dfs(node.left))
            right = max(0, dfs(node.right))
            cur = node.val + left + right
            res = max(res, cur)
            return node.val + max(left, right)
        dfs(root)
        return res


if __name__ == "__main__":
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node1.left = node2
    node1.right = node3
    print(Solution().maxPathSum(node1))
