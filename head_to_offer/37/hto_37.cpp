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
#include <array>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node) {
                out << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                out << "null ";
            }
        }
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream input(data);
        string val;
        vector<TreeNode*> vec;
        while (input >> val) {
            if (val == "null") {
                vec.push_back(nullptr);
            } else {
                vec.push_back(new TreeNode(stoi(val)));
            }
        }
        int j = 1;
        for (int i = 0; j < vec.size(); i++) {
            if (vec[i] == nullptr) continue;
            if (j < vec.size()) vec[i]->left  = vec[j++];
            if (j < vec.size()) vec[i]->right = vec[j++];
        }
        return vec[0];
    }

    void traverse(TreeNode *root) {
        cout << root->val << " ";
        if (root->left)  traverse(root->left);
        if (root->right) traverse(root->right);
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
    node3->left = node4;
    node4->right = node5;
    Codec s;
    cout << s.serialize(node1) << endl;

    TreeNode *node = s.deserialize(s.serialize(node1));
    s.traverse(node);
}


