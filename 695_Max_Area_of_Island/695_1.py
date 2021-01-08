from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        count, res = 0, 0
        row_dir = [-1, 1, 0, 0]
        col_dir = [0, 0, -1, 1]

        def dfs(i, j):
            nonlocal count
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != 1:
                return
            grid[i][j] = 2
            count += 1
            for k in range(4):
                newX = i + row_dir[k]
                newY = j + col_dir[k]
                dfs(newX, newY)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j)
                    res = max(res, count)
                    count = 0
        return res
