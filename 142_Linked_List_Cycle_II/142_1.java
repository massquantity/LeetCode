public class Solution {
    public ListNode detectCycle(ListNode head) {
        Set<ListNode> s = new HashSet<>();
        while (head != null)
        {
            if (s.contains(head)) return head;
            else                s.add(head);
            head = head.next;
        }
        return null;
    }
}