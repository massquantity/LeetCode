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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<vector<int>> res;
        stack<pair<TreeNode*, vector<int>>> stack;
        stack.push({root, {root->val}});
        while (!stack.empty()) {
            pair<TreeNode*, vector<int>> p = stack.top();
            stack.pop();
            int sumVector = accumulate(p.second.begin(), p.second.end(), 0);
            if (!p.first->left && !p.first->right && sumVector == sum)
                res.emplace_back(p.second);
            if (p.first->left) {
                vector<int> tmp(p.second);
                tmp.emplace_back(p.first->left->val);
                stack.push({p.first->left, tmp});
            }
            if (p.first->right) {
                vector<int> tmp(p.second);
                tmp.emplace_back(p.first->right->val);
                stack.push({p.first->right, tmp});
            }
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
    for (vector<int> v : s.pathSum(node1, 27)) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

