from typing import List

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        return self.reversePrint(head.next) + [head.val] if head else []


if __name__ == "__main__":
    node1 = ListNode(1)
    node2 = ListNode(3)
    node3 = ListNode(2)
    node1.next = node2
    node2.next = node3
    s = Solution()
    res = s.reversePrint(node1)
    print(res)