class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        ans = ListNode(0)
        ans.next = head
        val1, val2 = ans, ans

        for _ in range(n):
            val1 = val1.next

        while val1.next:
            val1 = val1.next
            val2 = val2.next

        val2.next = val2.next.next
        return ans.next