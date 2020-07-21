from typing import List, Dict
from queue import Queue
from collections import deque
import math


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        while head:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        return prev

    def reverseListRecursive(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        res = self.reverseListRecursive(head.next)
        head.next.next = head
        head.next = None
        return res


if __name__ == "__main__":
    s = Solution()
    node1 = ListNode(0)
    node2 = ListNode(1)
    node3 = ListNode(2)
    node1.next = node2
    node2.next = node3
    node = s.reverseList(node1)
    while node:
        print(node.val, end=" ")
        node = node.next
