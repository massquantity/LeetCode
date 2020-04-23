class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pprev = dummy, prev = head, curr = head.next;
        while (true) {
            for (int i = 0; i < k; ++i) {
                if (head == null) return dummy.next;
                head = head.next;
            }
            for (int i = 0; i < k - 1; i++) {
                ListNode tmp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = tmp;
            }
            pprev.next = prev;
            for (int i = 0; i < k; i++)
                pprev = pprev.next;
            pprev.next = curr;
            if (head == null || head.next == null) return dummy.next;
            prev = head;
            curr = head.next;
        }
    }
}