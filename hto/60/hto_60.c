#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

double* twoSum(int n, int* returnSize){
    int width = 6 * n + 1;
    int dp[12][100] = {0};
    for (int i = 0; i <= 6; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= 6*i; j++) {
            for (int cur = 1; cur <= 6; cur++) {
                if (j - cur <= 0) break;
                dp[i][j] += dp[i-1][j-cur];
            }
        }
    }
    // double all = pow(6.0, (double)n);
    int m = n;
    double all = 1.;
    while (m--)  all *= 6.;
    double *res = (double *)malloc(sizeof(double) * width);
    int j = 0;
    for (int i = n; i <= 6 * n; i++) {
        res[j++] = dp[n][i] / all;
    }
    *returnSize = j;
    return res;
}


int main(void) {
    int x = 0;
    double *res = twoSum(2, &x);
    while (*res != 0) {
        printf("%lf ", *res);
        res++;
    }
}

