class Solution:
    def rotateRight(self, head, k):
        if not head or not head.next:
            return head
        val1 = head
        count = 1
        while val1.next:
            val1 = val1.next
            count += 1
        val1.next = head
        for _ in range(count - k % count):
            val1 = val1.next
        head = val1.next
        val1.next = None
        return head