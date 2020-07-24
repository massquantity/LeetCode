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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        TreeNode *first;
        TreeNode *second;
        queue<TreeNode *> qq;
        qq.push(root->left);
        qq.push(root->right);
        while (!qq.empty()) {
            first = qq.front();
            qq.pop();
            second = qq.front();
            qq.pop();
            if (!first && !second) continue;
            if (!first || !second || first->val != second->val) return false;
            qq.push(first->left);
            qq.push(second->right);
            qq.push(first->right);
            qq.push(second->left);
        }
        return true;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(3);
    node1->left = node2; node1->right = node3;
    node2->left = node4; node3->right = node5;
    Solution s;
    cout << boolalpha << s.isSymmetric(node1) << endl;
}

