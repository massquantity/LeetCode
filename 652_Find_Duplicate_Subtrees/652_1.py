from collections import defaultdict
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        res = []
        trees = defaultdict(lambda: 0)

        def findSubTree(node):
            if not node:
                return "#"
            left =  findSubTree(node.left)
            right = findSubTree(node.right)
            subtree = str(node.val) + "," + left + "," + right
            if trees[subtree] == 1:
                res.append(node)
            trees[subtree] += 1
            return subtree

        findSubTree(root)
        return res
