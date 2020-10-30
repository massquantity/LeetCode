class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        a, b, c, d = 0, float("-inf"), 0, float("-inf")
        for p in prices:
            a = max(a, b + p)
            b = max(b, -p)
            c = max(c, d + p)
            d = max(d, a - p)
        return c
        """
        n = len(prices)
        dp = [[[0] * 2 for _ in range(3)] for _ in range(n)]
        for i in range(n):
            for k in range(2, 0, -1):
                if i - 1 == -1:
                    dp[i][k][0] = 0
                    dp[i][k][1] = -prices[i]
                    continue
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
        return dp[n-1][2][0]