# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy
        for _ in range(m - 1):
            pre = pre.next
        head = pre.next
        for i in range(m, n):
            nxt = head.next
            head.next = nxt.next
            nxt.next = pre.next
            pre.next = nxt
        return dummy.next