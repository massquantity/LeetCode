import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) return res;
        Deque<Integer> tmp = new ArrayDeque<>();
        backtrack(root, sum, tmp);
        return res;
    }

    private void backtrack(TreeNode root, int sum, Deque<Integer> tmp) {
        if (root == null) return;
        tmp.addLast(root.val)
        if (root.left == null && root.right == null && root.val == sum)
            res.add(new ArrayList<>(tmp));
        backtrack(root.left,  sum - node.val, tmp);
        backtrack(root.right, sum - node.val, tmp);
        tmp.removeLast();
    }
}

