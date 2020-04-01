from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [1] + [0]*n
        for i in range(0,m):
            for j in range(0,n):
                dp[j] = 0 if obstacleGrid[i][j] else dp[j]+dp[j-1]
        return dp[-2]


if __name__ == "__main__":
    aa = [[0 for _ in range(3)] for _ in range(3)]
    aa[1][1] = 1
    s = Solution()
    print(s.uniquePathsWithObstacles(aa))