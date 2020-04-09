class Solution {
public:
    vector<vector<int>> pathSum2(TreeNode *root, int sum) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res2;
        stack<pair<TreeNode*, vector<int>>> s;
        s.push({root, {root->val}});
        while (!s.empty()) {
            pair<TreeNode*, vector<int>> p = s.top(); s.pop();
            int sumVector = accumulate(p.second.begin(), p.second.end(), 0);
            if (!p.first->left && !p.first->right && sum == sumVector)
                res2.emplace_back(p.second);
            if (p.first->left) {
                vector<int> tmp{p.second};
                tmp.emplace_back(p.first->left->val);
                s.push({p.first->left, tmp});
            }
            if (p.first->right) {
                vector<int> tmp{p.second};
                tmp.emplace_back(p.first->right->val);
                s.push({p.first->right, tmp});
            }
        }
        return res2;
    }

    vector<vector<int>> pathSum3(TreeNode *root, int sum) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res3;
        stack<TreeNode*> treeNodeStack;
        stack<vector<int>> valStack;
        treeNodeStack.push(root);
        valStack.push({root->val});
        while (!treeNodeStack.empty()) {
            TreeNode *node = treeNodeStack.top(); treeNodeStack.pop();
            vector<int> vals = valStack.top(); valStack.pop();
            int sumVector = accumulate(vals.begin(), vals.end(), 0);
            if (!node->left && !node->right && sum == sumVector)
                res3.emplace_back(vals);
            if (node->left) {
                vector<int> tmp = vals;
                tmp.emplace_back(node->left->val);
                treeNodeStack.push(node->left);
                valStack.push(tmp);
            }
            if (node->right) {
                vector<int> tmp{vals};
                tmp.emplace_back(node->right->val);
                treeNodeStack.push(node->right);
                valStack.push(tmp);
            }
        }
        return res3;
    }

private:
    vector<vector<int>> res;
};