class Solution:
    def numSquares(self, n: int) -> int:
        squares = [i**2 for i in range(1, int(sqrt(n)) + 1)]
        dp = [float("inf")] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for squ in squares:
                if squ > i:
                    break
                dp[i] = min(dp[i], dp[i - squ] + 1)
        return dp[-1]
