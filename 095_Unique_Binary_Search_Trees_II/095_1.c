#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * treeCopy(struct TreeNode *);
static void traverse(struct TreeNode *);

struct TreeNode** generateTrees(int n, int* returnSize){    // dynamic programming
    struct TreeNode **res = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 20000);
    if (n == 0) { *returnSize = 0; return NULL; }
    res[0] = NULL;
    int count = 1;
    for (int i = 1; i <= n; ++i) {
        int curCount = 0;
        struct TreeNode **cur = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 20000);
        for (int m = 0; m < count; ++m) {
            struct TreeNode *oldNode = res[m];
            struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            newNode->val = i;
            newNode->left = oldNode;
            newNode->right = NULL;
            cur[curCount++] = newNode;
            for (int j = 0; j < i - 1; ++j) {
                struct TreeNode *oldNodeCopy = treeCopy(oldNode);
                struct TreeNode *rightNode = oldNodeCopy;
                for (int k = 0; k < j; ++k) {
                    if (rightNode == NULL) break;
                    rightNode = rightNode->right;
                }
                if (rightNode == NULL) break;
                struct TreeNode *orgRightTree = rightNode->right;
                newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                newNode->val = i;
                newNode->left = orgRightTree;
                newNode->right = NULL;
                rightNode->right = newNode;
                cur[curCount++] = oldNodeCopy;
            }
        }
        count = curCount;
        for (int c = 0; c < curCount; ++c)
            res[c] = cur[c];
        *returnSize = curCount;
        free(cur);
    }
    return res;
}

struct TreeNode * treeCopy(struct TreeNode *oldNode) {
    if (oldNode == NULL) return oldNode;
    struct TreeNode *newNode1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode1->val = oldNode->val;
    newNode1->left  = treeCopy(oldNode->left);
    newNode1->right = treeCopy(oldNode->right);
    return newNode1;
}

static void traverse(struct TreeNode *tree) {
    printf("%d ", tree->val);
    if (tree->left)  traverse(tree->left);
    if (tree->right) traverse(tree->right);
}


int main(void) {
    int a = 0;
    struct TreeNode** trees = generateTrees(3, &a);
    int p = 0;
    while (trees[p]) {
        traverse(trees[p]);
        p++;
        printf("\n");
    }
}