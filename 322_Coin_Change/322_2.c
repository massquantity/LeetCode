#define min(a, b) (a) < (b) ? (a) : (b)
// 完全背包
int coinChange(int* coins, int coinsSize, int amount){
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }
    dp[0] = 0;
    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}
