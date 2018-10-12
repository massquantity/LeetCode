public class Solution {
    public ListNode detectCycle(ListNode head) 
    {
        ListNode slow = head;
        ListNode fast = head;

        while (true)
        {
            if (fast == null || fast.next == null) return null;
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) break;
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}