struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head){
    if (!head) return head;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *cur, *pre;
    while (head && head->next) {
        if (head->val <= head->next->val) {
            head = head->next;
            continue;
        }
        pre = dummy;
        while (pre->next->val < head->next->val) 
            pre = pre->next;
        
        cur = head->next;
        head->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
    }
    return dummy->next;
}
