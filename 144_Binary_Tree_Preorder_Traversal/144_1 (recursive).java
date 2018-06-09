class Solution 
{
    private static void prepare(TreeNode root, List ans) 
    {
        if (root == null)
            return;
        ans.add(root.val);
        if (root.left != null)
            prepare(root.left, ans);
        if (root.right != null)
            prepare(root.right, ans);
    }

    public List<Integer> preorderTraversal(TreeNode root) 
    {
        List ans = new ArrayList();
        prepare(root, ans);
        return ans;
    }
}