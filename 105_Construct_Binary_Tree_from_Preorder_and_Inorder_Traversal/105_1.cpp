class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        int length = inorder.size();
        for (int i = 0 ; i < length; i++) {
            map[inorder[i]] = i;
        }
        return buildBranch(preorder, inorder, 0, 0, length - 1);
    }

    TreeNode* buildBranch(vector<int> &preorder, vector<int> &inorder, int first, int left, int right) {
        if (left > right) return nullptr;
        TreeNode *root = new TreeNode(preorder[first]);
        int mid = map[preorder[first]];
        root->left = buildBranch(preorder, inorder, first + 1, left, mid - 1);
        root->right = buildBranch(preorder, inorder, first + mid - left + 1, mid + 1, right);
        return root;
    }

private:
    unordered_map<int, int> map;
};