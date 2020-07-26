#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        bfs(root, 0, res);
        return res;
    }

    void bfs(TreeNode *node, int level, vector<vector<int>> &res) {
        if (level >= res.size()) res.push_back({});
        if (level % 2 == 0) res[level].emplace_back(node->val);
        else  res[level].insert(res[level].begin(), node->val);
        if (node->left)  bfs(node->left,  level + 1, res);
        if (node->right) bfs(node->right, level + 1, res);
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left  = node2;
    node1->right = node3;
    node2->left  = node4;
    node3->right = node5;
    Solution s;
    for (const auto &i : s.levelOrder(node1)) {
        for (const auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}