/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> map;
        findSubtree(root, res, map);
        return res;
    }

    string findSubtree(TreeNode *node, vector<TreeNode*> &res, 
                       unordered_map<string, int> &map) {
        if (!node) return "#";
        string left =  findSubtree(node->left, res, map);
        string right = findSubtree(node->right, res, map);
        string subTree = to_string(node->val) + "," + left + "," + right;
        if (map[subTree] == 1) res.emplace_back(node);
        map[subTree]++;
        return subTree;
    }
};
