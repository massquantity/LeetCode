struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pprev = dummy, *prev = head, *curr = head->next;
    while (true) {
        for (int i = 0; i < k; ++i) {
            if (head == NULL) return dummy->next;
            head = head->next;
        }
        struct ListNode *ppprev = prev;
        for (int i = 0; i < k - 1; i++) {
            struct ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        pprev->next = prev;
    //    for (int i = 0; i < k; i++)
    //        pprev = pprev->next;
        pprev = ppprev;
        pprev->next = curr;
        if (!head || !head->next) return dummy->next;
        else {
            prev = head;
            curr = head->next;
        }
    }
}