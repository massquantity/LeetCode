#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val)       return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(void) {
	struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode)); node1->val = 1;
	struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode)); node2->val = 2;
	struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode)); node3->val = 3;
	node1->left = node2; node1->right = node3; 
	node2->left = NULL; node2->right = NULL; node3->left = NULL; node3->right = NULL;
	struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode)); node4->val = 1;
	struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode)); node5->val = 2;
	struct TreeNode *node6 = (struct TreeNode *)malloc(sizeof(struct TreeNode)); node6->val = 3;
	node4->left = node5;  node4->right = node6;
	node5->left = NULL; node5->right = NULL; node6->left = NULL; node6->right = NULL;
	printf("%s\n", isSameTree(node1, node4) ? "true" : "false");
}