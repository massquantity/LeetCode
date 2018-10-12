class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return head

        curr = head
        prev = None
        while curr and curr.next:
            if curr.val == curr.next.val:
                currVal = curr.val
                while curr and curr.val == currVal:
                    curr = curr.next
                if prev:
                    prev.next = curr
                else:
                    head = curr
            else:
                prev = curr
                curr = curr.next
        return head