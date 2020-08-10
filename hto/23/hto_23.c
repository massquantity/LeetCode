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

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (true) {
        if (!fast || !fast->next) return NULL;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    while (head != fast) {
        head = head->next;
        fast = fast->next;
    }
    return head;
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
    struct ListNode *node = detectCycle(node1);
    printf(node ? "true" : "false");
}


