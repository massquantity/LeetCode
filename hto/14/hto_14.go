func cuttingRope(n int) int {
    dp := make([]int, n+1)
    dp[2] = 1
    for i := 3; i <= n; i++ {
        for j := 2; j < i; j++ {
            dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]))
        }
    }
    return dp[n]
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}
