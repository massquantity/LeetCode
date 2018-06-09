class Solution
{
    public List<Integer> preorderTraversal(TreeNode root)
    {
        List ans = new ArrayList();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        if (root == null)
            return ans;
        stack.push(root);
        while (root != null && !stack.isEmpty())
        {
            root = stack.pop();
            ans.add(root.val);
            if (root.right != null)
                stack.push(root.right);
            if (root.left != null)
                stack.push(root.left);
        }
        return ans;
    }
}