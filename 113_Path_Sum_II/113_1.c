#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool dfs(struct TreeNode *root, int sum, int subSum, int **res,
         int **returnColumnSizes, int *temp, int index, int *size) {
    if (!root) return false;
    subSum += root->val;
    if (!root->left && !root->right && subSum == sum) {
        temp[index++] = root->val;
        res[*size] = (int *)malloc(sizeof(int) * index);
        for (int i = 0; i < index; ++i)
            res[*size][i] = temp[i];
        returnColumnSizes[0][(*size)++] = index;
        return true;
    }
    temp[index++] = root->val;
    bool left  = dfs(root->left,  sum, subSum, res, returnColumnSizes, temp, index, size);
    bool right = dfs(root->right, sum, subSum, res, returnColumnSizes, temp, index, size);
    return left || right;
}

int** pathSum(struct TreeNode *root, int sum, int *returnSize, int **returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * 1024);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1024);
    *returnSize = 0;
    int size = 0;
    int subSum = 0;
    int index = 0;
    int temp[1024] = {0};
    if (dfs(root, sum, subSum, res, returnColumnSizes, temp, index, &size)) {
        *returnSize = size;
        return res;
    }
    return NULL;
}

int main(void) {
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node8 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node9 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node10 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 5; node2->val = 4; node3->val = 8; node4->val = 11;
    node5->val = 13; node6->val = 4; node7->val = 7; node8->val = 2;
    node9->val = 5; node10->val = 1;
    node1->left = node2; node1->right = node3; node2->left = node4;
    node3->left = node5; node3->right = node6;
    node4->left = node7; node4->right = node8;
    node6->left = node9; node6->right = node10;
    int r = 1;
    int *returnSize = &r;
    int **retColumnSizes = &returnSize;
    int **res = pathSum(node1, 22, returnSize, retColumnSizes);
    for (int i = 0; i < *returnSize; ++i) {
        printf("[ ");
        for (int j = 0; j < **retColumnSizes; ++j) {
            printf("%d ", res[i][j]);
        }
        printf("]\n");
    }
}

