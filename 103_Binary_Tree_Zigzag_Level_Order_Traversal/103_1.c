#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// returnSize: 3  returnColumnSizes: [1, 2, 2]
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    int **res = (int **)malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    struct TreeNode *queue[10000];
    size_t count, begin = 0, end = 1;
    queue[begin] = root;
    while ((count = end - begin)) {
        res[*returnSize] = (int *)malloc(sizeof(int) * count);
        for (int i = 0; i < count; ++i) {
            struct TreeNode *t = queue[begin++];
            if ((*returnSize) % 2 == 0)  // root to level 1, reverse add
                res[*returnSize][i] = t->val;
            else
                res[*returnSize][count - i - 1] = t->val;
            if (t->left)  queue[end++] = t->left;
            if (t->right) queue[end++] = t->right;
        }
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
    }
    return res;
}

static void traverse(struct TreeNode *tree) {
    printf("%d ", tree->val);
    if (tree->left)  traverse(tree->left);
    if (tree->right) traverse(tree->right);
}

int main(void) {
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 5;
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = node5;
    int r;
    int *r1 = &r;
    int **res = zigzagLevelOrder(node1, r1, &r1);
//    printf("%lu\n", sizeof(res));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j)
            printf("%d ", res[i][j]);
        printf("\n");
    }
}

