class Solution
{
    int min_value = Integer.MAX_VALUE;
    Integer prev = null;

    public int getMinimumDifference(TreeNode root)
    { 
        if (root == null) return min_value;

        getMinimumDifference(root.left);

        if (prev != null) min_value = Math.min(min_value, root.val - prev);
        prev = root.val;

        getMinimumDifference(root.right);

        return min_value;
    }
}