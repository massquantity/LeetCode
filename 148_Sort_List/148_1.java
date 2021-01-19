/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode sortList(ListNode head) {
        int len = getLen(head);
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        for (int i = 1; i < len; i *= 2) {
            ListNode cur = dummy.next, pre = dummy;
            while (cur != null) {
                ListNode left  = cur;
                ListNode right = split(left, i);
                cur = split(right, i);
                pre.next = merge(left, right);
                while (pre.next != null) 
                    pre = pre.next; 
            }
        }
        return dummy.next;
    }

    private int getLen(ListNode node) {
        int i = 0;
        while (node != null) {
            i++;
            node = node.next;
        }
        return i;
    }

    ListNode split(ListNode node, int step) {
        if (node == null) return null;
        ListNode cur = node;
        for (int i = 1; i < step && cur.next != null; i++) {
            cur = cur.next;
        }
        ListNode tmp = cur.next;
        cur.next = null;
        return tmp;
    }

    ListNode merge(ListNode left, ListNode right) {
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        while (left != null && right != null) {
            if (left.val < right.val) {
                cur.next = left;
                left = left.next;
            } else {
                cur.next = right;
                right = right.next;
            }
            cur = cur.next;
        }
        cur.next = left != null ? left : right;
        return dummy.next;
    }
}
