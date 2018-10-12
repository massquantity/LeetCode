public class Solution {
    public ListNode detectCycle(ListNode head) 
    {
        if (head == null || head.next == null) return null;
        if (head.next == head) return head;
        if (head.next.next == head) return head;
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) break;
        }
        if (fast == null || fast.next == null) return null;
        slow = head;
        while (slow != fast)
        {
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}