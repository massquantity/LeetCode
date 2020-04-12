import java.util.Arrays;
import java.util.Comparator;
import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    List<Integer> tmp = new ArrayList<>();
    public int[] reversePrint(ListNode head) {
        recursive(head);
        int[] res = new int[tmp.size()];
        for (int i = 0; i < tmp.size(); i++)
            res[i] = tmp.get(i);
        return res;
    }

    private void recursive(ListNode node) {
        if (node == null) return;
        recursive(node.next);
        tmp.add(node.val);
    }
}

public class leetcode {
    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(3);
        ListNode node3 = new ListNode(2);
        node1.next = node2;
        node2.next = node3;
        Solution s = new Solution();
        for (int res : s.reversePrint(node1))
            System.out.print(res + " ");
    }
}