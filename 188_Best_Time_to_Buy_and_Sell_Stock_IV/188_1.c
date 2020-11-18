#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int greedyApproach(int *prices, int pricesSize) {
    int res = 0;
    for (int i = 1; i < pricesSize; i++) {
        int tmp = prices[i] - prices[i - 1];
        if (tmp > 0) res += tmp;
    }
    return res;
}

int maxProfit(int k, int* prices, int pricesSize){
    if (!pricesSize) return 0;
    if (k >= pricesSize / 2) return greedyApproach(prices, pricesSize);
    int dp[k + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; i++) {
        dp[i][0] = 0;
        dp[i][1] = -prices[0];
    }

    for (int i = 1; i < pricesSize; i++) {
        for (int j = k; j >= 0; j--) {
            dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
            dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
        }
    }
    return dp[k][0];
}


int main(void) {
    int prices[] = {7,1,5,3,6,4};
    printf("%d\n", maxProfit(2, prices, 6));
}

