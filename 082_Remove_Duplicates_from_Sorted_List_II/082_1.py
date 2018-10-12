class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return head

        prev = None
        curr = head
        while curr and curr.next:
            if curr.val != curr.next.val:
                prev = curr
                curr = curr.next
            else:
                while curr.next and curr.val == curr.next.val:
                    curr = curr.next
                if prev is not None:
                    prev.next = curr.next
                else:
                    head = curr.next
                curr = curr.next
        return head