#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;
    struct Node *cur = head;
    while (cur != NULL) {
        struct Node *copyNode = (struct Node *)malloc(sizeof(struct Node));
        copyNode->val = cur->val;
        copyNode->next = cur->next;
        cur->next = copyNode;
        cur = cur->next->next;
    }

    cur = head;
    while (cur != NULL) {
        if (cur->random) {
            cur->next->random = cur->random->next;
        } else {
            cur->next->random = NULL;
        }
        cur = cur->next->next;
    }

    struct Node *dummy = head->next;
    cur = head;
    struct Node *curCopy = head->next;
    while (cur != NULL) {
        cur->next = cur->next->next;
        cur = cur->next;
        if (curCopy->next) {
            curCopy->next = curCopy->next->next;
            curCopy = curCopy->next;
        }
    }
    return dummy;
}


int main(void) {
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node5 = (struct Node *)malloc(sizeof(struct Node));
    node1->val = 7; node2->val = 13; node3->val = 11;
    node4->val = 10; node5->val = 1;
    node1->next = node2; node2->next = node3; node3->next = node4;
    node4->next = node5;
    node1->random = node5; node2->random = node1;
    node3->random = node5; node4->random = node3; node5->random = node1;
    struct Node *node = copyRandomList(node1);
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
}

