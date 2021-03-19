object Solution {
    def reverseList(head: ListNode): ListNode = {
        if (head == null || head.next == null) 
            return head
        val res = reverseList(head.next)
        head.next.next = head
        head.next = null
        res
    }
}
