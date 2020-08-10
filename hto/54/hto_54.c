int res;
int *count;

int kthLargest(struct TreeNode* root, int k){
    count = &k;
    dfs(root, count);
    return res;
}

void dfs(struct TreeNode *node, int *k) {
    if (!node || (*k) == 0) return;
    dfs(node->right, k);
    (*k)--;
    if ((*k) == 0) {
        res = node->val;
        return;
    }
    dfs(node->left, k);
}

