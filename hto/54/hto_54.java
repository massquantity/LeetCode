class Solution {
    int res, k;
    public int kthLargest(TreeNode root, int k) {
        this.k = k;
        dfs(root);
        return res;
    }

    private void dfs(TreeNode root) {
        if (root == null || k == 0) return;
        dfs(root.right);
        if (--k == 0) {
            res = root.val;
            return;
        }
        dfs(root.left);
    }
}