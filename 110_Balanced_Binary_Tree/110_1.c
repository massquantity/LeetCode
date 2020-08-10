#define abs(x, y) ((x) - (y) >= 0 ? (x) - (y) : (y) - (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int depth(struct TreeNode *root) {
    if (!root) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    if (left == -1 || right == -1 || abs(left, right) > 1) return -1;
    return 1 + max(left, right);
}

bool isBalanced(struct TreeNode* root){
    return depth(root) != -1;
}