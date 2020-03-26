#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode * findMiddleElement(struct ListNode *head) {
    struct ListNode *prevPtr = NULL;
    struct ListNode *slowPtr = head;
    struct ListNode *fastPtr = head;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        prevPtr = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    if (prevPtr != NULL) prevPtr->next = NULL;
    return slowPtr;
}

struct TreeNode * sortedListToBST(struct ListNode *head){
    if (head == NULL) return NULL;
    struct ListNode *mid = findMiddleElement(head);
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = mid->val;
    node->left = NULL;
    node->right = NULL;
    if (head == mid) return node;
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);
    return node;
}

static void traverse(struct TreeNode *tree) {
    printf("%d ", tree->val);
    if (tree->left)  traverse(tree->left);
    if (tree->right) traverse(tree->right);
}

int main(void) {
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = -10;
    node2->val = -3;
    node3->val = 0;
    node4->val = 5;
    node5->val = 9;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    traverse(sortedListToBST(node1));
}

