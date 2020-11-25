from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        if not matrix:
            return matrix 
        m, n = len(matrix), len(matrix[0])
        row_flag, col_flag = False, False
        for i in range(m):
            if matrix[i][0] == 0:
                row_flag = True
                break
        
        for i in range(n):
            if matrix[0][i] == 0:
                col_flag = True
                break
        
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if row_flag:
            for i in range(m):
                matrix[i][0] = 0

        if col_flag:
            for j in range(n):
                matrix[0][j] = 0
        