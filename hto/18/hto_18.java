import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if (head == null) return head;
        if (head.val == val) return head.next;
        ListNode pre = head;
        ListNode cur = head.next;
        while (cur != null && cur.val != val) {
            pre = cur;
            cur = cur.next;
        }
        if (cur != null) pre.next = cur.next;
        return head;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        ListNode node1 = new ListNode(4);
        ListNode node2 = new ListNode(5);
        ListNode node3 = new ListNode(1);
        ListNode node4 = new ListNode(8);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        ListNode node = s.deleteNode(node1, 1);
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
    }
}