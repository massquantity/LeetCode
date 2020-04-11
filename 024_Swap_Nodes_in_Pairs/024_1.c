/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy;
    while (head && head->next) {
        struct ListNode *start = head;
        struct ListNode *end = head->next;

        start->next = end->next;
        end->next = start;
        prev->next = end;

        head = start->next;
        prev = start;
    }
    return dummy->next;
}