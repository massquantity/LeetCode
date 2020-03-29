#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        vector<int> left_in, right_in, left_post, right_post;
        TreeNode *root = new TreeNode(postorder.back());
        int mid;
        for (mid = 0; mid < inorder.size(); ++mid)
            if (inorder[mid] == postorder.back())
                break;

        for (int i = 0; i < mid; ++i) {
            left_in.emplace_back(inorder[i]);
            left_post.emplace_back(postorder[i]);
        }

        for (int i = mid + 1; i < inorder.size(); ++i) {
            right_in.emplace_back(inorder[i]);
            right_post.emplace_back(postorder[i - 1]);
        }

        root->left  = buildTree(left_in, left_post);
        root->right = buildTree(right_in, right_post);
        return root;
    }

    static void traverse(TreeNode *root) {
        if (!root) return;
        cout << root->val << " ";
        traverse(root->left);
        traverse(root->right);
    }
};

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution s;
    Solution::traverse(s.buildTree(inorder, postorder));
}


