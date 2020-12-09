from typing import List

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        
        res, m, n = 0, len(matrix), len(matrix[0])
        height = [0 for _ in range(n+2)]
        for i in range(m):
            stack = [0]
            for j in range(1, n+2):
                if j-1 < n and matrix[i][j-1] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
                while height[stack[-1]] > height[j]:
                    curHeight = height[stack.pop()]
                    curWidth = j - stack[-1] - 1
                    res = max(res, curHeight * curWidth)
                stack.append(j)
        return res
