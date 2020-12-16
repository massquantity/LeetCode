#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxCoins(int* nums, int numsSize){
    int n = numsSize;
    int dp[n+2][n+2];
    int points[n+2];
    memset(dp, 0, sizeof(dp));
    memset(points, 0, sizeof(points));
    points[0] = points[n+1] = 1;
    for (int i = 1; i <= n; i++) {
        points[i] = nums[i-1];
    }

    for (int i = n; i >= 0; i--) {
        for (int j = i + 1; j < n + 2; j++) {
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i][k] + dp[k][j] + points[i] * points[j] * points[k]
                );
            }
        }
    }
    return dp[0][n+1];
}

int main(void) {
    int nums[] = {3,1,5,8};
    printf("%d\n", maxCoins(nums, 4));
}
