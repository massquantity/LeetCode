class Solution:
    def detectCycle(self, head):
        fast, slow = head, head
        while True:
            if not fast or not fast.next:
                return None
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                break

        slow = head
        while slow != fast:
            fast = fast.next
            slow = slow.next
        return slow