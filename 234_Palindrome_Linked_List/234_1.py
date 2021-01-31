# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        if not head.next:
            return True
        if not head.next.next:
            return head.val == head.next.val
        pre, cur, fast = None, head, head
        while fast and fast.next:
            fast = fast.next.next
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp

        if fast:
            cur = cur.next
        while cur:
            if pre.val != cur.val:
                return False
            pre = pre.next
            cur = cur.next
        return True
