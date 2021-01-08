/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(struct TreeNode *root, int *res) {
    if (root == NULL) return 0;
    int left  = max(0, dfs(root->left, res));
    int right = max(0, dfs(root->right, res));
    int cur = root->val + left + right;
    *res = max(*res, cur);
    return root->val + max(left, right);
}

int maxPathSum(struct TreeNode* root){
    int res = INT_MIN;
    dfs(root, &res);
    return res;
}
