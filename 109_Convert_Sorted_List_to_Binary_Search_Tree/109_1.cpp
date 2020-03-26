#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) { }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        while (head) {
            values.emplace_back(head->val);
            head = head->next;
        }
        return convertListToBST(0, values.size() - 1);
    }

    TreeNode * convertListToBST(int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(values[mid]);
        if (left == right) return node;
        node->left = convertListToBST(left, mid - 1);
        node->right = convertListToBST(mid + 1, right);
        return node;
    }

    static void traverse(struct TreeNode *tree) {
        printf("%d ", tree->val);
        if (tree->left)  traverse(tree->left);
        if (tree->right) traverse(tree->right);
    }
private:
    vector<int> values;
};


int main() {
    ListNode *node1 = new ListNode(-10);
    ListNode *node2 = new ListNode(-3);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(9);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution s;
    Solution::traverse(s.sortedListToBST(node1));
}