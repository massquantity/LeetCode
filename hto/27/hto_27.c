#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root) return root;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root->left)  invertTree(root->left);
    if (root->right) invertTree(root->right);
    return root;
}

struct TreeNode *invertTree2(struct TreeNode *root) {
    if (!root) return root;
    struct TreeNode *left = invertTree2(root->right);
    struct TreeNode *right = invertTree2(root->left);
    root->left = left;
    root->right = right;
    return root;
}

int main(void) {
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 4; node2->val = 2; node3->val = 7;
    node4->val = 1; node5->val = 3; node6->val = 6; node7->val = 9;
    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;
    node3->left = node6; node3->right = node7;
    struct TreeNode *node = invertTree(node1);
}
