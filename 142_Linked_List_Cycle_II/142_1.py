class Solution:
    def detectCycle(self, head):
        s = set()
        while head:
            if head in s:
                return head
            else:
                s.add(head)
            head = head.next
        return None