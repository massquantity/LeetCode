class Solution:
    def detectCycle(self, head):
        if not head or not head.next:
            return None
        if head == head.next:
            return head
        if head == head.next.next:
            return head
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                break
        if not fast or not fast.next:
            return None
        slow = head
        while slow != fast:
            fast = fast.next
            slow = slow.next
        return slow