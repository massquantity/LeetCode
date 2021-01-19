class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        while head and head.next:
            if head.val <= head.next.val:
                head = head.next
                continue
            pre = dummy
            while pre.next.val < head.next.val:
                pre = pre.next
            cur = head.next
            head.next = cur.next
            cur.next = pre.next
            pre.next = cur
        return dummy.next
