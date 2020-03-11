#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int * inorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * 100);
    struct TreeNode *stack[100];
    // struct TreeNode **stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*1000);
    int i = 0;
    int k = 0;
    while (true) {
        while (root) {
            stack[i++] = root;
            root = root->left;
        }
        if (i == 0) break;
        root = stack[--i];
        res[k++] = root->val;
        root = root->right;
    }
    *returnSize = k;
    return res;
}


int main(void) {
    struct TreeNode *a = (struct TreeNode *)malloc(sizeof(struct TreeNode)); a->val = 1;
    struct TreeNode *b = (struct TreeNode *)malloc(sizeof(struct TreeNode)); b->val = 2;
    struct TreeNode *c = (struct TreeNode *)malloc(sizeof(struct TreeNode)); c->val = 3;
    printf("%d %d %d\n", a->val, b->val, c->val);
    a->right = b;
    b->left = c;
    a->left = NULL;
    b->right = NULL;
    c->left = NULL;
    c->right = NULL;
    int abc = 0;
    int *size = &abc;
    int *res = inorderTraversal(a, size);
    printf("%d %d %d\n", res[0], res[1], res[2]);
    free(a);
    free(b);
    free(c);
}