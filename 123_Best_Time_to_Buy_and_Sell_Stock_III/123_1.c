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

int maxProfit(int* prices, int pricesSize){
    if (!pricesSize) return 0;
    int dp[pricesSize][3][2];
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    dp[0][2][0] = 0;
    dp[0][2][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
        dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
    }
    return dp[pricesSize - 1][2][0];
}



int main(void) {
    int prices[] = {7,1,5,3,6,4};
    printf("%d\n", maxProfit(prices, 6));
}

