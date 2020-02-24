struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // recursion
public:
    static bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        return isSymmetricLeftRight(root->left, root->right);
    }

    static bool isSymmetricLeftRight(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && 
                isSymmetricLeftRight(left->left, right->right) && 
                isSymmetricLeftRight(left->right, right->left);
    }
};

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(2);
    TreeNode *d = new TreeNode(3);
    TreeNode *e = new TreeNode(4);
    TreeNode *f = new TreeNode(4);
    TreeNode *g = new TreeNode(3);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    cout << Solution::isSymmetric(a) << endl;
}