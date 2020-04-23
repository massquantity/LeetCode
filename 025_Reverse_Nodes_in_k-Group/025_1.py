from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        pprev = dummy
        prev = head
        curr = head.next
        while True:
            for _ in range(k):
                if not head:
                    return dummy.next
                head = head.next

            for _ in range(k - 1):
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp

            pprev.next = prev
            for _ in range(k):
                pprev = pprev.next
            pprev.next = curr

            if not head or not head.next:
                return dummy.next
            prev = head
            curr = head.next


if __name__ == "__main__":
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node5 = ListNode(5)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    s = Solution()
    res = s.reverseKGroup(node1, 3)
    for i in range(5):
        print(res.val, end=" ")
        if i < 4:
            print("-> ", end="")
        res = res.next
