#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

long lastVal = LONG_MIN;

bool isValidBST(struct TreeNode * root) {
    if (!root) return true;
    if (!isValidBST(root->left))  return false;
    if (root->val <= lastVal) return false;
    lastVal = (long)root->val;
    if (!isValidBST(root->right)) return false;
    return true;
}

int main(void) {
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 2; node2->val = 1; node3->val = 3;
    node1->left = node2; node1->right = node3;
    node2->left = NULL; node2->right = NULL; node3->left = NULL; node3->right = NULL;
    printf("%s\n", isValidBST(node1) ? "true" : "false");
    free(node1);
    free(node2);
    free(node3);
}

