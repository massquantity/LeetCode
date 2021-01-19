bool isInterleave(char * s1, char * s2, char * s3){
  size_t m = strlen(s1), n = strlen(s2);
  if (m + n != strlen(s3)) return false;
  bool dp[m+1][n+1];
  memset(dp, false, sizeof(dp));
  dp[0][0] = true;
  for (int i = 1; i <= m && s1[i-1] == s3[i-1]; i++) dp[i][0] = true;
  for (int j = 1; j <= n && s2[j-1] == s3[j-1]; j++) dp[0][j] = true;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int k = i + j;
      dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[k-1]) ||
                 (dp[i][j-1] && s2[j-1] == s3[k-1]);
    }
  }
  return dp[m][n];
}