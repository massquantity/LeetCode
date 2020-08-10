from typing import List, Dict
from queue import Queue
from collections import deque
import math
import itertools


class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def dfs(cur: 'Node') -> None:
            if not cur:
                return
            dfs(cur.left)
            if self.pre:
                self.pre.right, cur.left = cur, self.pre
            else:
                self.head = cur
            self.pre = cur
            dfs(cur.right)

        if not root:
            return
        self.pre = None
        dfs(root)
        self.head.left, self.pre.right = self.pre, self.head
        return self.head


if __name__ == "__main__":
    node1 = Node(4)
    node2 = Node(2)
    node3 = Node(1)
    node4 = Node(3)
    node5 = Node(5)
    node1.left = node2
    node1.right = node5
    node2.left = node3
    node2.right = node4
    s = Solution()
    nn = s.treeToDoublyList(node1)
    start = nn.val
    i = 0
    while nn:
        print(nn.val, end=" ")
        i += 1
        nn = nn.right
        if nn.val == start and i > 1:
            break
