#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode *n1;
    struct ListNode *n2;
    n1 = n2 = dummy;
    for (int i = 0; i < n; ++i)
        n1 = n1->next;

    while (n1->next) {
        n1 = n1->next;
        n2 = n2->next;
    }
    n2->next = n2->next->next;
    return dummy->next;
}

int main(void) {
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1; node2->val = 2; node3->val = 3; node4->val = 4; node5->val = 5;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1 = removeNthFromEnd(node1, 2);
    while (node1) {
        printf("%d ", node1->val);
        node1 = node1->next;
    }
}








