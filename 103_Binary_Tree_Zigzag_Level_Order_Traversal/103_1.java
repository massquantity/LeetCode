import java.util.List;
import java.util.LinkedList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int v) { val = v; }
}

class Solution {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return new LinkedList<List<Integer>>();
        List<LinkedList<Integer>> res = new LinkedList<>();
        preOrder(root, 0, res);
        return (List)res;
    }

    void preOrder(TreeNode node, int depth, List<LinkedList<Integer>> res) {
        if (depth >= res.size()) res.add(new LinkedList<Integer>());
        if (depth % 2 == 0)     res.get(depth).offer(node.val);
        else                    res.get(depth).offerFirst(node.val);
        if (node.left  != null) preOrder(node.left,  depth + 1, res);
        if (node.right != null) preOrder(node.right, depth + 1, res);
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
        List<List<Integer>> res = s.zigzagLevelOrder(node1);
        for (List<Integer> ll : res) {
            for (Integer l : ll)
                System.out.print(l + " ");
            System.out.println();
        }
    }
}