class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode curr = head;
        ListNode prev = dummy;
        while (curr != null && curr.next != null)
        {
            while (curr.next != null && curr.val == curr.next.val)
                curr = curr.next;
            if (prev.next == curr)
                prev = prev.next;
            else
                prev.next = curr.next;
            curr = curr.next;
        }
        return dummy.next;
    }    
}