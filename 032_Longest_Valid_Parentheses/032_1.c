#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int longestValidParentheses(char * s){
    size_t size = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * size);
    memset(dp, 0, sizeof(int) * size);
    int maxVal = 0;
    for (int i = 1; i < size; i++) {
        if (s[i] == ')') {
            int former_cur = i - 1 - dp[i - 1];
            int former = former_cur - 1;
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (former_cur >= 0 && s[former_cur] == '(') {
                dp[i] = dp[i - 1] + 2;
                if (former >= 0) {
                    dp[i] = dp[i] + dp[former];
                }
            }
        }
        maxVal = maxVal > dp[i] ? maxVal : dp[i];
    }
    free(dp);
    return maxVal;
}

int main(void) {
    char *s = ")()())))";
    printf("%d\n", longestValidParentheses(s));
}

