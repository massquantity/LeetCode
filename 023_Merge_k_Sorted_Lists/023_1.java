import java.util.PriorityQueue;
import java.util.Collections;
import java.util.Comparator;


class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if (lists.length == 0) 
			return null;

		ListNode dummy = new ListNode(0);
		ListNode cur = dummy;
		PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>() {
			@Override
			public int compare(ListNode l1, ListNode l2) {
				return l1.val - l2.val;
			}
		});

		for (ListNode list : lists) {
			if (list == null)
				continue;
			pq.add(list);
		}

		while (!pq.isEmpty()) {
			ListNode nextNode = pq.poll();
			cur.next = nextNode;
			cur = cur.next;
			if (nextNode.next != null)
				pq.add(nextNode.next);
		}
		return dummy.next;
	}
}

public class leetcode {
	public static void main(String[] args) {
		ListNode l1 = new ListNode(1);
	    ListNode l2 = new ListNode(5);
	    ListNode l3 = new ListNode(7);
	    l1.next = l2;
	    l2.next = l3;
	    ListNode l4 = new ListNode(2);
	    ListNode l5 = new ListNode(4);
	    ListNode l6 = new ListNode(6);
	    l4.next = l5;
	    l5.next = l6;
	    ListNode l7 = new ListNode(3);
	    ListNode l8 = new ListNode(8);
	    ListNode l9 = new ListNode(9);
	    l7.next = l8;
	    l8.next = l9;
	    ListNode[] lists = {l1, l4, l7};
	    Solution s = new Solution();;
	    ListNode res = s.mergeKLists(lists);
	    do {
	        System.out.println(res.val + " ");
	        res = res.next;
	    } while (res != null);
	}
}