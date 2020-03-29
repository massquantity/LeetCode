import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    Map<Integer, Integer> indexMap = new HashMap<>();
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length == 0) return null;
        int length = inorder.length;
        for (int i = 0; i < length; ++i)
            indexMap.put(inorder[i], i);
        return buildBranch(preorder, 0, 0, length - 1);
    }

    // first is in preorder, while left and right are in inorder.
    private TreeNode buildBranch(int[] preorder, int first, int left, int right) {
        if (left > right) return null;
        TreeNode root = new TreeNode(preorder[first]);
        int mid = indexMap.get(preorder[first]);
        root.left  = buildBranch(preorder, first + 1, left, mid - 1);
        // (mid - left) means whole left tree length
        root.right = buildBranch(preorder, first + mid - left + 1, mid + 1, right);
        return root;
    }

    public static void traverse(TreeNode root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        traverse(root.left);
        traverse(root.right);
    }
}


public class leetcode {
    public static void main(String[] args) {
        int[] preorder = {3, 9, 20, 15, 7};
        int[] inorder = {9, 3, 15, 20, 7};
        Solution s = new Solution();
        Solution.traverse(s.buildTree(preorder, inorder));
    }
}
