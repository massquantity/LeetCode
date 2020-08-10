#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy = node;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            node->next = l1;
            l1 = l1->next;
        } else {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    node->next = l1 ? l1 : l2;
    return dummy->next;
}

int main(void) {

    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1; node2->val = 2; node3->val = 4;
    node4->val = 1; node5->val = 3; node6->val = 4;
    node1->next = node2; node2->next = node3; node3->next = NULL;
    node4->next = node5; node5->next = node6; node6->next = NULL;

    struct ListNode *res = mergeTwoLists(node1, node4);
    while (res) {
        printf("%d ", res->val);
        res = res->next;
    }
}