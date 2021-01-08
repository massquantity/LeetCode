struct TreeNode *subset(int *nums, int left, int right) {
    if (right < left) return NULL;
    int mid = (left + right) >> 1;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    
        root->left  = subset(nums, left, mid - 1);
        root->right = subset(nums, mid + 1, right);
    
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (numsSize == 0) return NULL;
    return subset(nums, 0, numsSize - 1);
}
