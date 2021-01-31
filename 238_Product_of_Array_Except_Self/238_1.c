int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *res = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        res[i] = 1;
    }
    int left = 1, right = 1;
    for (int i = 0; i < numsSize; i++) {
        res[i] *= left;
        left *= nums[i];
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}
