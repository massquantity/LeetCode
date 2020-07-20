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

struct ListNode* deleteNode(struct ListNode* head, int val){
    if (!head) return head;
    if (head->val == val) return head->next;
    struct ListNode *dummy = head;
    while (head->next && head->next->next) {
        if (head->next->val == val) {
            head->next = head->next->next;
            break;
        }
        head = head->next;
    }
    if (head->next && head->next->val == val) {
        head->next = NULL;
    }
    return dummy;
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
    struct ListNode *node = deleteNode(node1, 6);
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
}

