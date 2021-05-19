int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i] - 1) % numsSize;
        nums[index] += numsSize;
    }
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= numsSize) {
            res[(*returnSize)++] = i + 1;
        } 
    }
    return res;
}
