class Solution:
    def addTwoNumbers(self, l1, l2):
        carry = 0
        s = res = ListNode(0)
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next

            val = carry % 10
            carry = carry // 10
            # carry, val = divmod(carry, 10)
            s.next = ListNode(val)
            s = s.next
        return res.next