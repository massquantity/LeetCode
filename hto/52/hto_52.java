class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode h1 = headA, h2 = headB;
        while (h1 != h2) {
            h1 = h1 != null ? h1.next : headB;
            h2 = h2 != null ? h2.next : headA;
        }
        return h1;
    }
}



