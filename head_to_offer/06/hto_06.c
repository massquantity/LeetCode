void postOrder(struct ListNode *node, int *res, int *returnSize) {
    if (!node) return;
    postOrder(node->next, res, returnSize);
    res[(*returnSize)++] = node->val;
}

int *reversePrint(struct ListNode *head, int *returnSize){
    int *res = (int *)malloc(sizeof(int) * 1024);
    *returnSize = 0;
    postOrder(head, res, returnSize);
    return res;
}