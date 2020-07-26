import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.LinkedList;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}


class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> res = new ArrayList<>();
		if (root == null) return res;
		Queue<TreeNode> queue = new LinkedList<>();
	//	Queue<TreeNode> queue = new ArrayDeque<>();
		queue.add(root);
		while (!queue.isEmpty()) {
			int count = queue.size();
			List<Integer> resIn = new ArrayList<>();
			while (count-- > 0) {
				TreeNode t = queue.poll();
				resIn.add(t.val);
				if (t.left  != null) queue.add(t.left);
				if (t.right != null) queue.add(t.right);
			}
			res.add(resIn);
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
		List<List<Integer>> res = s.levelOrder(a);
		for (List<Integer> l : res) {
			for (Integer ll : l)
				System.out.print(l + " ");
		}
	}
}
