#define min(x, y) (x) < (y) ? (x) : (y);

int nthUglyNumber(int n){
    int a = 0, b = 0, c = 0;
    int dp[1690] = {0};
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
        int m = min(n3, n5);
        dp[i] = min(n2, m);
        if (dp[i] == n2) a++;
        if (dp[i] == n3) b++;
        if (dp[i] == n5) c++;
    }
    return dp[n-1];
}
