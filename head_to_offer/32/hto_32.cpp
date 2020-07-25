#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <bitset>
#include <array>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode *dummy = q.front();
            res.emplace_back(dummy->val);
            q.pop();
            if (dummy->left)  q.emplace(dummy->left);
            if (dummy->right) q.emplace(dummy->right);
        }
        return res;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(20);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node5 = new TreeNode(7);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node3->right = node5;
    Solution s;
    for (auto i : s.levelOrder(node1)) {
        cout << i << " ";
    }
}

