#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// this method is slow...
int rob(struct TreeNode* root){
    if (root == NULL) return 0;
    int level1 = rob(root->left) + rob(root->right);
    int level2 = root->val;
    if (root->left) level2 += (rob(root->left->left) + rob(root->left->right));
    if (root->right) level2 += (rob(root->right->left) + rob(root->right->right));
    return level1 > level2 ? level1 : level2;
}

int main(void) {
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 3;
    node2->val = 2;
    node3->val = 3;
    node4->val = 3;
    node5->val = 1;
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node3->right = node5;
    printf("%d\n", rob(node1));
}

