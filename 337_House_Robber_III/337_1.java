import java.util.Map;
import java.util.HashMap;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
   TreeNode(int x) { val = x; }
}

class Solution {
    Map<TreeNode, Integer> memo = new HashMap<>();

    public int rob(TreeNode root) {
        if (root == null) return 0;
        if (memo.containsKey(root)) return memo.get(root);
        int level1 = rob(root.left) + rob(root.right);
        int level2 = root.val;
        if (root.left != null) 
            level2 += (rob(root.left.left) + rob(root.left.right));
        if (root.right != null)
            level2 += (rob(root.right.left) + rob(root.right.right));
        int res = Math.max(level1, level2);
        memo.put(root, res);
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(3);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(3);
        TreeNode node5 = new TreeNode(1);
        node1.left = node2;
        node1.right = node3;
        node2.right = node4;
        node3.right = node5;
        Solution s = new Solution();
        System.out.println(s.rob(node1));
    }
}