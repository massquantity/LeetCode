class Solution {    
public:
    static bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode *first;
        TreeNode *second;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            first = q.front();
            q.pop();
            second = q.front();
            q.pop();
            if (!first && !second) continue;
            if (!first || !second) return false;
            if (first->val != second->val) return false;
            q.push(first->left);
            q.push(second->right);
            q.push(first->right);
            q.push(second->left);
        }
        return true;
    }
};