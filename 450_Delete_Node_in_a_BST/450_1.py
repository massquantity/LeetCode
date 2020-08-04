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
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        def get_min(node):
            while node.left is not None:
                node = node.left
            return node

        if not root:
            return
        if root.val == key:
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            minNode = get_min(root.right)
            root.val = minNode.val
            root.right = self.deleteNode(root.right, minNode.val)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        return root

def traverse(node: TreeNode) -> None:
    print(node.val, end=" ")
    if node.left:
        traverse(node.left)
    if node.right:
        traverse(node.right)


if __name__ == "__main__":
    node1 = TreeNode(5)
    node2 = TreeNode(3)
    node3 = TreeNode(6)
    node4 = TreeNode(2)
    node5 = TreeNode(4)
    node6 = TreeNode(7)
    node1.left = node2
    node1.right = node3
    node2.left = node4
    node2.right = node5
    node3.right = node6
    s = Solution()
    node = s.deleteNode(node1, 3)
    traverse(node)

