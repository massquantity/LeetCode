from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        # left, right, top, bottom
        l, r, t, b = 0, len(matrix[0]) - 1, 0, len(matrix) - 1
        res = []
        while True:
            for i in range(l, r + 1):
                res.append(matrix[t][i])
            t += 1
            if t > b:
                break
            for i in range(t, b + 1):
                res.append(matrix[i][r])
            r -= 1
            if l > r:
                break
            for i in range(r, l - 1, -1):
                res.append(matrix[b][i])
            b -= 1
            if t > b:
                break
            for i in range(b, t - 1, -1):
                res.append(matrix[i][l])
            l += 1
            if l > r:
                break
        return res