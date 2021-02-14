int change(int amount, int* coins, int coinsSize){
  if (coinsSize == 0) {
      if (amount == 0) 
        return 1;
      else            
        return 0;
  }
  int dp[coinsSize][amount + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = coins[0]; i <= amount; i += coins[0]) 
    dp[0][i] = 1;
  for (int i = 1; i < coinsSize; i++) {
    for (int j = 0; j <= amount; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= coins[i]) 
        dp[i][j] += dp[i][j - coins[i]];
    }
  }
  return dp[coinsSize - 1][amount];
}
