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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res;
        deque<TreeNode*> queue;
        queue.emplace_back(root);
        queue.emplace_back(nullptr);
        deque<int> resIn;
        bool is_left = true;
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop_front();
            if (node) {
                if (is_left)     resIn.emplace_back(node->val);
                else             resIn.emplace_front(node->val);
                if (node->left)  queue.emplace_back(node->left);
                if (node->right) queue.emplace_back(node->right);
            } else {
                res.emplace_back(begin(resIn), end(resIn));
                resIn.clear();
                if (!queue.empty()) queue.emplace_back(nullptr);
                is_left = !is_left;
            }
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
    node1->left  = node2;
    node1->right = node3;
    node2->left  = node4;
    node3->right = node5;
    Solution s;
    for (const auto &i : s.zigzagLevelOrder(node1)) {
        for (const auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}