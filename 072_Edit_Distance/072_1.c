#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a, b, c) ((a) < ((b) < (c) ? (b) : (c)) ? (a) : ((b) < (c) ? (b) : (c)));


int minDistance(char * word1, char * word2){
    size_t m = strlen(word1), n = strlen(word2);
    int dp[m + 1][n + 1];
 /*   for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;  */
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if      (i == 0 && j == 0) dp[i][j] = 0;
            else if (i == 0)           dp[i][j] = j;
            else if (j == 0)           dp[i][j] = i;
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   dp[i][j - 1],
                                   dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}


int main(void) {
    char *w1 = "intention", *w2 = "execution";
    printf("%d\n", minDistance(w1, w2));
}

