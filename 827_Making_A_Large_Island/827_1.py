from typing import List

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = 0
        has_zero = False

        def dfs(i, j, visited):
            if (
                i < 0 or 
                i >= m or 
                j < 0 or 
                j >= n or 
                grid[i][j] == 0 or 
                visited[i][j]
            ):
                return 0
            visited[i][j] = True
            return (
                1 + 
                dfs(i - 1, j, visited) + 
                dfs(i + 1, j, visited) + 
                dfs(i, j - 1, visited) + 
                dfs(i, j + 1, visited)
            )

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    grid[i][j] = 1
                    has_zero = True
                    visited = [[False] * n for _ in range(m)]
                    area = dfs(i, j, visited)
                    res = max(res, area)
                    grid[i][j] = 0
        return res if has_zero else m * n
