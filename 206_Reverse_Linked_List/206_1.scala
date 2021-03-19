object Solution {
    def reverseList(head: ListNode): ListNode = {
        var cur: ListNode = head
        var pre: ListNode = null
        while (cur != null) {
            val tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        }
        pre
    }
}
