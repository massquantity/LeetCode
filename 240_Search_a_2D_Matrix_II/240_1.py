from typing import List

class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        def binarySearch(array, target):
            lo, hi = 0, len(array) - 1
            while lo < hi:
                mid = lo + (hi - lo) // 2
                if array[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid
            return array[lo] == target

        for i in range(len(matrix)):
            if binarySearch(matrix[i], target):
                return True
        return False


if __name__ == "__main__":
    arr = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
    s = Solution()
    print(s.findNumberIn2DArray(arr, 5))