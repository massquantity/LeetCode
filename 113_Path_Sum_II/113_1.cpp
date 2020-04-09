class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<int> v;
        dfs(root, v, sum);
        return res;
    }

    void dfs(TreeNode *root, vector<int> &v, int sum) {
        if (!root) return;
        v.emplace_back(root->val);
        if (!root->left && !root->right && root->val == sum)
            res.emplace_back(v);
        dfs(root->left, v, sum - root->val);
        dfs(root->right, v, sum - root->val);
        v.pop_back();
    }

private:
    vector<vector<int>> res;
};