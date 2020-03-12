#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};


class Solution {  // dynamic programming
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> res;
        if (n == 0)
            return res;
        res.push_back(nullptr);
        for (int i = 1; i <= n; i++) {
            vector<TreeNode *> cur;
            for (const auto & oldNode : res) {
                TreeNode *newNode = new TreeNode(i);
                newNode->left = oldNode;
                cur.push_back(newNode);
                for (int j = 0; j < i - 1; ++j) {
                    TreeNode *oldNodeCopy = treeCopy(oldNode);
                    TreeNode *rightNode = oldNodeCopy;
                    for (int k = 0; k < j; ++k) {
                        if (rightNode == nullptr) break;
                        rightNode = rightNode->right;
                    }
                    if (rightNode == nullptr) break;
                    TreeNode *rightTree = rightNode->right;
                    newNode = new TreeNode(i);
                    rightNode->right = newNode;
                    newNode->left = rightTree;
                    cur.push_back(oldNodeCopy);
                }
            }
            res = cur;
        }
        return res;
    }

    static TreeNode * treeCopy(TreeNode *oldNode) {
        if (oldNode == nullptr) return oldNode;
        TreeNode *newNode = new TreeNode(oldNode->val);
        newNode->left = treeCopy(oldNode->left);
        newNode->right = treeCopy(oldNode->right);
        return newNode;
    }

    static void traverse(TreeNode * tree) {
        cout << tree->val << " ";
        if (tree->left)  traverse(tree->left);
        if (tree->right) traverse(tree->right);
    }
};



int main() {
    Solution s;
    vector<TreeNode *> trees = s.generateTrees(3);
    for (const auto & t : trees) {
        Solution::traverse(t);
        cout << "\n";
    }
}