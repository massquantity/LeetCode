struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if (!root) return NULL;
    if (root->val == key) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        struct TreeNode *minNode = root->right;
        while (minNode->left) minNode = minNode->left;
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    return root;
}