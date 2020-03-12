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
    public List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> res = new LinkedList<>();
        if (start > end) {
            res.add(null);
            return res;
        }
        for (int i = start; i <= end; i++) {
            List<TreeNode> leftTrees  = generateTrees(start, i - 1);
            List<TreeNode> rightTrees = generateTrees(i + 1, end);
            for (TreeNode l : leftTrees) {
                for (TreeNode r : rightTrees) {
                    TreeNode s = new TreeNode(i);
                    s.left = l;
                    s.right = r;
                    res.add(s);
                }
            }
        }
        return res;
    }


    public List<TreeNode> generateTrees(int n) {
        if (n == 0)
            return new LinkedList<TreeNode>();
        else
            return generateTrees(1, n);
    }
}


public class leetcode {
	public static void main(String[] args) {
		Solution s =  new Solution();
		List<TreeNode> res = s.generateTrees(3);
		for (TreeNode r : res) {  // traversal trees
			Queue<TreeNode> queue = new ArrayDeque<>();
        	queue.add(r);
        	while (!queue.isEmpty()) {
        		int count = queue.size();
        		while (count-- > 0) {
        			TreeNode t = queue.poll();
        			System.out.print(t.val + " ");
        			if (t.left != null) queue.add(t.left);
        			if (t.right != null) queue.add(t.right);
        		}
        	}
        	System.out.println();
		}
	}
}