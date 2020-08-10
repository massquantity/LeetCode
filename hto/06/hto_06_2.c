struct ListNode *reverseList(struct ListNode *node, int *returnSize) {
    if (!node) return NULL;
    struct ListNode *pre = NULL;
    struct ListNode *cur = node;
    while (cur) {
        (*returnSize)++;
        struct ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int *reversePrint(struct ListNode *head, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * 1024);
    int i = 0;
    *returnSize = 0;
    head = reverseList(head, returnSize);
    while (head) {
        res[i++] = head->val;
        head = head->next;
    }
    return res;
}