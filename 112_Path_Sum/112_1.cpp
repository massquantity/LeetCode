class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->left == nullptr && root->right == nullptr)
            return sum == root->val;
        return hasPathSum(root->left, sum - root->val) || 
            hasPathSum(root->right, sum - root->val);
    }
};