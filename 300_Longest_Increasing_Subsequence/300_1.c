#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLIS(int *nums, int numsSize){
    if (numsSize == 0) return 0;
    int res = 1;
    int dp[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        dp[i] = 1;
    }
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < i; ++j)
            if (nums[j] < nums[i])
                dp[i] = MAX(dp[i], dp[j] + 1);
    }
    for (int i = 0; i < numsSize; ++i) {
        res = MAX(res, dp[i]);
    }
    return res;
}

int main(void) {
    int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("%d\n", lengthOfLIS(a, sizeof(a) / sizeof(int)));
}
