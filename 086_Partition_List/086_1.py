# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        dummySmall = ListNode(-1)
        dummyBig = ListNode(-1)
        small, big = dummySmall, dummyBig
        while head:
            if head.val < x:
                small.next = ListNode(head.val)
                small = small.next
            else:
                big.next = ListNode(head.val)
                big = big.next
            head = head.next
        big.next = None
        small.next = dummyBig.next
        return dummySmall.next