#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

bool isMatch(char *s, char *p){
    size_t m = strlen(s);
    size_t n = strlen(p);
    bool dp[m+1][n+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i-1] && p[i-1] == '*';
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}


int main(void) {
    printf("%s\n", isMatch("cb", "?b*") ? "true" : "false");
}

