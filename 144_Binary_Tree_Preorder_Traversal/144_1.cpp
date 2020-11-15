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
#include <sstream>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x): val(x), left(nullptr), right(nullptr)  { }
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) { }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode *> stack;
        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                res.push_back(root->val);
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            root = root->right;
        }
        return res;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node3->left = node5;
    Solution s;
    for (int i : s.preorderTraversal(node1)) {
        cout << i << " ";
    }
}

