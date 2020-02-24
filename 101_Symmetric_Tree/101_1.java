class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)  return true;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root.left);
        queue.add(root.right);
        while (!queue.isEmpty()) {
            TreeNode first =  queue.poll();
            TreeNode second = queue.poll();
            if (first == null && second == null) continue;
            if (first == null || second == null) return false;
            if (first.val != second.val)         return false;
            queue.add(first.left);
            queue.add(second.right);
            queue.add(first.right);
            queue.add(second.left);
        }
        return true;
    }
}