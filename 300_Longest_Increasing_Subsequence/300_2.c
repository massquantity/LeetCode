#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLIS(int *nums, int numsSize){
    if (numsSize == 0) return 0;
    int res = 1;
    int dp[numsSize];
    dp[0] = 1;
    for (int i = 1; i < numsSize; ++i) {
        int maxVal = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i])
                maxVal = MAX(maxVal, dp[j]);
        }
        dp[i] = maxVal + 1;
        res = MAX(res, dp[i]);
    }
    return res;
}