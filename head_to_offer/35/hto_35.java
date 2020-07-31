import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Map;
import java.util.HashMap;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = next;
        this.random = random;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> mm = new HashMap<>();
        Node cur = head;
        while (cur != null) {
            mm.put(cur, new Node(cur.val));
            cur = cur.next;
        }

        cur = head;
        while (cur != null) {
            mm.get(cur).next = mm.get(cur.next);
            mm.get(cur).random = mm.get(cur.random);
            cur = cur.next;
        }
        return mm.get(head);
    }
}

public class leetcode {
    public static void main(String[] args) {
        Node node1 = new Node(7);
        Node node2 = new Node(13);
        Node node3 = new Node(11);
        Node node4 = new Node(10);
        Node node5 = new Node(1);
        node1.next = node2; 
        node2.next = node3; 
        node3.next = node4;
        node4.next = node5;
        node1.random = node5; 
        node2.random = node1;
        node3.random = node5; 
        node4.random = node3; 
        node5.random = node1;
        Solution s = new Solution();
        Node node = s.copyRandomList(node1);
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
    }
}


