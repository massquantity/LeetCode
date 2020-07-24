bool isSymmetricLeftRight(struct TreeNode *left, struct TreeNode *right) {
    if (!left && !right) return true;
    if (!left || !right || left->val != right->val) return false;
    return isSymmetricLeftRight(left->right, right->left)
        && isSymmetricLeftRight(left->left, right->right);
}

bool isSymmetric(struct TreeNode* root){
    if (!root) return true;
    return isSymmetricLeftRight(root->left, root->right);
}

