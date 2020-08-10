struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        struct ListNode *h1 = headA, *h2 = headB;
        while (h1 != h2) {
            h1 = h1 ? h1->next : headB;
            h2 = h2 ? h2->next : headA;
        }
        return h1;
}