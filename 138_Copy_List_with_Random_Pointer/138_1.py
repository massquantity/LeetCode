from typing import List, Dict
from queue import Queue
from collections import deque
import math
import itertools


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        cur = head
        while cur:
            copyNode = Node(cur.val)
            copyNode.next = cur.next
            cur.next = copyNode
            cur = copyNode.next

        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        
        dummy = head.next
        cur = head
        curCopy = head.next
        while cur:
            cur.next = cur.next.next
            cur = cur.next
            if curCopy.next:
                curCopy.next = curCopy.next.next
                curCopy = curCopy.next
        return dummy

