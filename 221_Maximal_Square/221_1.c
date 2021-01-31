#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (!matrix || matrixSize == 0 || *matrixColSize == 0) return 0;
    int res = 0;
    int m = matrixSize, n = *matrixColSize;
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
    }
    return res * res;
}
