#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (!head || !head->next) return false;
    struct ListNode *fast = head;
    while (fast && fast->next) {
        head = head->next;
        fast = fast->next->next;
        if (fast == head) return true;
    }
    return false;
}

int main(void) {
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1; node2->val = 2; node3->val = 3;
    node4->val = 4; node5->val = 5; node6->val = 6;
    node1->next = node2; node2->next = node3; node3->next = node4;
    node4->next = node5; node5->next = node6; node6->next = NULL;
    printf("%s\n", hasCycle(node1) ? "true" : "false");
}








