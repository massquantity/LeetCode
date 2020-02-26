class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists):
        length = len(lists)
        interval = 1
        while interval < length:
            for i in range(0, length - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if length > 0 else lists

    def merge2Lists(self, l1, l2):
        dummy = cur = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        if not l1:
            cur.next = l2
        else:
            cur.next = l1
        return dummy.next


if __name__ == "__main__":
    l1 = ListNode(1)
    l2 = ListNode(5)
    l3 = ListNode(7)
    l1.next = l2
    l2.next = l3
    l4 = ListNode(2)
    l5 = ListNode(4)
    l6 = ListNode(6)
    l4.next = l5
    l5.next = l6
    l7 = ListNode(3)
    l8 = ListNode(8)
    l9 = ListNode(9)
    l7.next = l8
    l8.next = l9
    s = Solution()
    res = s.mergeKLists([l1, l4, l7])
    while res:
        print(res.val)
        res = res.next
