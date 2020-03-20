from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.lower_upper(root, float("-inf"), float("inf"))

    def lower_upper(self, node: TreeNode, lower: int, upper: int) -> bool:
        if not node:
            return True
        val = node.val;
        if val <= lower or val >= upper:
            return False
        return self.lower_upper(node.left, lower, val) and \
               self.lower_upper(node.right, val, upper)


if __name__ == "__main__":
    node1 = TreeNode(5)
    node2 = TreeNode(1)
    node3 = TreeNode(4)
    node4 = TreeNode(3)
    node5 = TreeNode(6)
    node1.left = node2
    node1.right = node3
    node3.left = node4
    node3.right = node5
    s = Solution()
    print(s.isValidBST(node1))