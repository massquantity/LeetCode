class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        size = 0
        ptr = head
        while ptr:
            size += 1
            ptr = ptr.next

        def convert(l, r):
            nonlocal head
            if l > r:
                return None
            mid = (l + r ) // 2
            left = convert(l, mid - 1)
            node = TreeNode(head.val)
            node.left = left
            head = head.next
            node.right = convert(mid + 1, r)
            return node
        return convert(0, size - 1)