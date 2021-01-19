class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        size = self.get_size(head)
        dummy = ListNode(-1)
        dummy.next = head
        i = 1
        while i < size:
            pre, cur = dummy, dummy.next
            while cur:
                left = cur
                right = self.split(left, i)
                cur = self.split(right, i)
                pre.next = self.merge(left, right)
                while pre.next:
                    pre = pre.next
            i *= 2
        return dummy.next
    
    def get_size(self, node):
        i = 0
        while node:
            i += 1
            node = node.next
        return i

    def split(self, node, step):
        if not node:
            return node
        cur = node
        for i in range(1, step):
            if not cur.next:
                break
            cur = cur.next
        tmp = cur.next
        cur.next = None
        return tmp

    def merge(self, left, right):
        dummy2 = ListNode(-1)
        cur = dummy2
        while left and right:
            if left.val < right.val:
                cur.next = left
                left = left.next
            else:
                cur.next = right
                right = right.next
            cur = cur.next
        cur.next = left or right
        return dummy2.next
