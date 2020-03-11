import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Stack;


class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}


class Solution {
	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		Stack<TreeNode> ss = new Stack<>();
		while (true) {
			while (root != null) {
				ss.push(root);
				root = root.left;
			}
			if (ss.empty()) break;
			root = ss.pop();
			res.add(root.val);
			root = root.right;
		}
		return res;
	}
}


public class leetcode {
	public static void main(String[] args) {
		TreeNode a = new TreeNode(3);
		TreeNode b = new TreeNode(9);
		TreeNode c = new TreeNode(20);
		TreeNode d = new TreeNode(15);
		TreeNode e = new TreeNode(7);
		a.left = b;
		a.right = c;
		c.left = d;
		c.right = e;
		Solution s = new Solution();
		List<Integer> res = s.inorderTraversal(a);
		for (Integer l : res) {
			System.out.print(l + " ");
		}
	}
}

