inline int MAX(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return MAX(nums[0], nums[1]);
    int res = nums[0];
    nums[1] = MAX(nums[0], nums[1]);
    for (int i = 2; i < numsSize; ++i) {
        int tmp = nums[i - 2] + nums[i];
        nums[i] = MAX(nums[i - 1], tmp);
        res = MAX(res, nums[i]);
    }
    return res;
} 

int rob2(int* nums, int numsSize){
    int res = 0, prev = 0;
    for (int i = 0; i < numsSize; ++i) {
        int tmp = res;
        res = MAX(prev + nums[i], res);
        prev = tmp;
    }
    return res;
}