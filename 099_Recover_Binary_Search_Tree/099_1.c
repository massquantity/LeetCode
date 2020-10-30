struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inOrderTraverse(struct TreeNode *root, struct TreeNode **first, struct TreeNode **second, struct TreeNode **pre) {
    if (!root) return;
    inOrderTraverse(root->left, first, second, pre);
    if (!(*first) && *pre && root->val <= (*pre)->val) *first = *pre;
    if (*first && *pre && root->val <= (*pre)->val)  *second = root;
    *pre = root;
    inOrderTraverse(root->right, first, second, pre);
}

void recoverTree(struct TreeNode* root){
    struct TreeNode *first = NULL;
    struct TreeNode *second = NULL;
    struct TreeNode *pre = NULL;
    inOrderTraverse(root, &first, &second, &pre);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}