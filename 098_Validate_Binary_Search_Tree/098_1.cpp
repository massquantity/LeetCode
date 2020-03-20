#include <climits>
#include <vector>
#include <iostream>
#include <list>
#include <forward_list>
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        update(root, LONG_MIN, LONG_MAX);
        while (!queue.empty()) {
            root = queue.front();
            long l = lower.front();
            long h = upper.front();
            pop_first();
            if (!root) continue;
            int val = root->val;
            if (val <= l || val >= h) return false;
            if (root->left)  update(root->left, l, val);
            if (root->right) update(root->right, val, h);
        }
        return true;
    }

    void update(TreeNode *node, long low, long high) {
        queue.emplace_back(node);
        lower.emplace_back(low);
        upper.emplace_back(high);
    }

    void pop_first() {
        queue.pop_front();
        lower.pop_front();
        upper.pop_front();
    }

private:
    deque<TreeNode *> queue;
    deque<long> lower, upper;
};


int main() {
    TreeNode *node1 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
//    TreeNode *node_max = new TreeNode(2147483647);
    Solution s;
    cout << boolalpha << s.isValidBST(node1) << endl;
}

