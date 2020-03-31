#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    int dp[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main(void) {
    int m = 7, n = 3;
    printf("%d\n", uniquePaths(m, n));
}

