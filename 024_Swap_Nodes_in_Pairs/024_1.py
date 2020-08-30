from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        next_ = head.next
        head.next = self.swapPairs(next_.next)
        next_.next = head
        return next_


if __name__ == "__main__":
    s = Solution()
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    nn = s.swapPairs(node1)
    while nn:
        print(nn.val, end=" ")
        nn = nn.next
