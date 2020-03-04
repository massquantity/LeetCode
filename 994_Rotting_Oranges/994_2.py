from typing import List
import collections

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rotten_list = collections.deque()
        row_len = len(grid)
        col_len = len(grid[0])
        for i in range(row_len):
            for j in range(col_len):
                if grid[i][j] == 2:
                    rotten_list.append([i, j, 0])

        t = 0
        while rotten_list:
            r, c, t = rotten_list.popleft()
            for nr, nc in ((r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)):
                if 0 <= nr < row_len and 0 <= nc < col_len and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    rotten_list.append([nr, nc, t + 1])

        if (any(1 in row for row in grid)):
            return -1
        return t
