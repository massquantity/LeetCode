#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    if (!head || !head->next) return head;
    struct ListNode *res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}

struct ListNode* reverseList222(struct ListNode* head){
    struct ListNode *prev = NULL;
    while (head) {
        struct ListNode *temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }
    return prev;
}

struct ListNode* reverseList333(struct ListNode* head){
    struct ListNode *prev = NULL;
    while (head) {
        struct ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
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
    struct ListNode *node = reverseList333(node1);
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
}
