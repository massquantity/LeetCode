from typing import List, Dict

class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        if length < 2: return s
        dp = [[False for _ in range(length)] for _ in range(length)]
        for i in range(length): dp[i][i] = True
        max_len, start = 1, 0
        for i in range(length - 2, -1, -1):
            for j in range(i + 1, length):
                if s[i] == s[j]:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = False

                if dp[i][j]:
                    cur_len = j - i + 1
                    if cur_len > max_len:
                        max_len = cur_len
                        start = i
        return s[start: start + max_len]


if __name__ == "__main__":
    s = Solution()
    print(s.longestPalindrome("babad"))