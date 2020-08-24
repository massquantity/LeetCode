struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == p || root == q) return root;
    if (p->val < root->val && q->val > root->val) return root;
    if (q->val < root->val && p->val > root->val) return root;
    if (p->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else                    return lowestCommonAncestor(root->right, p, q);
}