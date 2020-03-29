#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildBranch(int *preorder, int *inorder, int inorderSize,
                             int first, int left, int right) {
    if (left > right) return NULL;
    int i;
    for (i = 0; i < inorderSize; ++i)
        if (preorder[first] == inorder[i])
            break;

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[first];
    root->left  = buildBranch(preorder, inorder, inorderSize, first + 1, left, i - 1);
    root->right = buildBranch(preorder, inorder, inorderSize, first + i - left + 1, i + 1, right);
    return root;
}

struct TreeNode* buildTree(int *preorder, int preorderSize,
        int *inorder, int inorderSize){
    if (preorder == NULL || preorderSize == 0) return NULL;
    return buildBranch(preorder, inorder, inorderSize, 0, 0, inorderSize - 1);

}

static void traverse(struct TreeNode *tree) {
    printf("%d ", tree->val);
    if (tree->left)  traverse(tree->left);
    if (tree->right) traverse(tree->right);
}


int main(void) {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    size_t preorderSize = sizeof(preorder) / sizeof(int);
    size_t inorderSize = sizeof(inorder) / sizeof(int);
    traverse(buildTree(preorder, preorderSize, inorder, inorderSize));
}

