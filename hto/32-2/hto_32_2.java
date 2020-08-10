import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new LinkedList<List<Integer>>();
        List<List<Integer>> res = new LinkedList<>();
        Deque<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        Deque<Integer> resIn = new LinkedList<>();
        Boolean is_left = true;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node != null) {
                if (is_left) resIn.offer(node.val);
                else         resIn.offerFirst(node.val);
                if (node.left  != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            } else {
                res.add(new LinkedList(resIn));
                resIn.clear();
                if (!queue.isEmpty()) queue.add(null);
                is_left = !is_left;
            }
        }
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        node1.left  = node2;
        node1.right = node3;
        node2.left  = node4;
        node3.right = node5;
        Solution s = new Solution();
        List<List<Integer>> res = s.levelOrder(node1);
        for (List<Integer> ll : res) {
            for (Integer l : ll)
                System.out.print(l + " ");
            System.out.println();
        }
    }
}


