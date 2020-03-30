#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    int dp[m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if      (i == 0) dp[j] = 1;          // 初始化
            else if (j != 0) dp[j] += dp[j - 1]; 
            // dp[i][j] = dp[i - 1][j] + dp[i][j - 1], dp[i - 1][j]对应于这里的dp[j], dp[i][j - 1]对应于这里的dp[j - 1]
        }
    }
    return dp[m - 1];
}

int main(void) {
    int m = 7, n = 3;
    printf("%d\n", uniquePaths(m, n));
}

