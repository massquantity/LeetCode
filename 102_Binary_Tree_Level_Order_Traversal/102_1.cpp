#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        preOrder(root, 0, res);
        return res;
    }

    void preOrder(TreeNode *node, int depth, vector<vector<int> > &res) {
        if (depth >= res.size())
            res.push_back(vector<int> {});
        res[depth].push_back(node->val);
        if (node->left)  preOrder(node->left,  depth + 1, res);
        if (node->right) preOrder(node->right, depth + 1, res);
    }
};


int main() {
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(9);
    TreeNode *c = new TreeNode(20);
    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;
    Solution s;
    for (auto ll : s.levelOrder(a)) {
        for (auto l : ll)
            cout << l << " ";
        cout << "\n";
    }
}