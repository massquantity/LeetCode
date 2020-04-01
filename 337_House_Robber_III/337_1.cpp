#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    int rob(TreeNode* root) {
        P res = dp(root);
        return max(res.first, res.second);
    }

private:
    P dp(TreeNode *root) {
        if (!root) return {0, 0};
        P left  = dp(root->left);
        P right = dp(root->right);
        int rob = root->val + left.first + right.first;
        int not_rob = max(left.first, left.second) + max(right.first, right.second);
        return {not_rob, rob};
    }
};


int main() {
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node3->right = node5;
    Solution s;
    cout << s.rob(node1) << endl;
}
