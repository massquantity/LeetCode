int comp(const void *p1, const void *p2) {
    return *(const int *)p1 - *(const int *)p2;
}

bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) return false;
    //qsort(nums, numsSize, sizeof(int), comp);
    int target = sum / 2;
    bool dp[target + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] |= dp[j - nums[i]];
        }
    }
    return dp[target];
}
