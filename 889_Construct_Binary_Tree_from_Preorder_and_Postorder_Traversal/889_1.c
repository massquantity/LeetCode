struct TreeNode* construct(int *pre, int *post, int pre_start, int pre_end, int post_start, int post_end) {
    if (pre_start > pre_end || post_start > post_end) return NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = pre[pre_start];
    if (pre_start == pre_end) return root;
    
    int index = post_start;
    while (pre[pre_start + 1] != post[index]) index++;

    root->left = construct(pre, post, pre_start + 1, pre_start + 1 + index - post_start, post_start, index);
    root->right = construct(pre, post, pre_start + 2 + index - post_start, pre_end, index + 1, post_end - 1);
    return root;
}

struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
    if (preSize == 0) return NULL;
    return construct(pre, post, 0, preSize - 1, 0, postSize - 1);

}