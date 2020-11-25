from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        m, n = len(matrix), len(matrix[0])
        lo, hi = 0, m * n - 1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            num = matrix[mid // n][mid % n]
            if target < num:
                hi = mid - 1
            elif target > num:
                lo = mid + 1
            else:
                return True
        return False
