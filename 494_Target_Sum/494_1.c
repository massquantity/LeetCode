int findTargetSumWays(int* nums, int numsSize, int S){
    int sum = 0;
    for (int i = 0; i < numsSize; i++) 
        sum += nums[i];
    if (S > sum) return 0;
    if ((S + sum) % 2 != 0) return 0;
    int target = (S + sum) / 2;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[target];
}
