/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head){
    if (!head) return true;
    if (!head->next) return true;
    if (!head->next->next) return head->val == head->next->val;
    struct ListNode *pre = NULL, *cur = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        struct ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    if (fast) {
        cur = cur->next;
    }
    while (cur) {
        if (cur->val != pre->val) 
            return false;
        pre = pre->next;
        cur = cur->next;
    }
    return true;
}
