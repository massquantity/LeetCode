/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    int i = 0;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *front = dummy;
    while (--m) {
        front = front->next;
        i++;
    }
    struct ListNode *prev = NULL;
    head = front->next;

    while (i < n) {
        struct ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
        i++;
    }
    front->next->next = head;
    front->next = prev;
    return dummy->next;
}