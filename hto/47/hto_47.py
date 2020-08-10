from typing import List, Dict
from queue import Queue
from collections import deque
import math
from collections import Counter

class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                elif i == 0:
                    grid[i][j] += grid[i][j-1]
                elif j == 0:
                    grid[i][j] += grid[i-1][j]
                else:
                    grid[i][j] += max(grid[i-1][j], grid[i][j-1])
        return grid[m-1][n-1]