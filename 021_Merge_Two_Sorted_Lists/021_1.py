class Solution:
    def mergeTwoLists(self, l1, l2):
        if None in (l1, l2):
            return l1 or l2

        dummy = cur = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 or l2
        return dummy.next