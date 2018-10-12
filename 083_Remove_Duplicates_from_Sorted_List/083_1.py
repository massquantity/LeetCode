class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res = head
        while res is not None and res.next is not None:
            if res.val == res.next.val:
                res.next = res.next.next
            else:
                res = res.next
        return head