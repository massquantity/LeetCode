int maxProduct(int* nums, int numsSize){
    int maxNums[numsSize], minNums[numsSize];
    maxNums[0] = nums[0];
    minNums[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        maxNums[i] = fmax(maxNums[i-1] * nums[i], fmax(nums[i], minNums[i-1] * nums[i]));
        minNums[i] = fmin(minNums[i-1] * nums[i], fmin(nums[i], maxNums[i-1] * nums[i]));
    }

    int res = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        res = fmax(res, maxNums[i]);
    }
    return res;
}
