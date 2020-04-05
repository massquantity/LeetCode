from typing import List

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        dp = [0 for _ in range(K + 1)]
        m = 0
        while dp[K] < N:
            m += 1
            for k in range(K, 0, -1):
                dp[k] += (dp[k - 1] + 1)
        return m


if __name__ == "__main__":
    s = Solution()
    print(s.superEggDrop(3, 14))