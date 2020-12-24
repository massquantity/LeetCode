class Solution:
    def numDecodings(self, s: str) -> int:
        if int(s) == 0 or s[0] == '0':
            return 0
        if len(s) == 1:
            return 1
        if s[1] == '0' and s[0] > '2':
            return 0

        n = len(s)
        dp = [0] * n
        dp[0] = 1
        dp[1] = 1 if s[1] == '0' or s[0] > '2' or (s[0] == '2' and s[1] > '6') else 2;
        for i in range(2, n):
            if s[i] == '0':
                if (s[i-1] == '1' or s[i-1] == '2'):
                    dp[i] = dp[i-2]
                else:
                    return 0
            elif s[i-1] == '1' or (s[i-1] == '2' and '1' <= s[i] <= '6'):
                dp[i] = dp[i-1] + dp[i-2]
            else:
                dp[i] = dp[i-1]
        
        return dp[n-1]
