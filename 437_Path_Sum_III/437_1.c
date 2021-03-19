int dfs(struct TreeNode *node, int sum) {
    if (!node) return 0;
    int count = node->val == sum ? 1 : 0;
    int tmp = sum - node->val;
    return count + dfs(node->left, tmp) + dfs(node->right, tmp);
}

int pathSum(struct TreeNode* root, int sum){
    if (!root) return 0;
    return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}
