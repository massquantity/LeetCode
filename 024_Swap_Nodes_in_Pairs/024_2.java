/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;
        while (prev.next != null && prev.next.next != null) {
            ListNode start = prev.next;
            ListNode end = prev.next.next;
            prev.next = end;
            start.next = end.next;
            end.next = start;
            prev = start;
        }
        return dummy.next;
    }
} 