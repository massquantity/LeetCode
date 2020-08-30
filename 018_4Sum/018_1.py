from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        length = len(nums)
        if not nums or length < 4:
            return []
        res = []
        self.quickSort(nums, 0, length - 1)
        for i in range(length - 3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i + 1, length - 2):
                if j == i + 1 or (j > i + 1 and nums[j-1] < nums[j]):
                    p, q = j + 1, length - 1
                    while p < q:
                        fSum = nums[i] + nums[j] + nums[p] + nums[q]
                        if fSum == target:
                            res.append([nums[i], nums[j], nums[p], nums[q]])
                            while p < q and nums[p] == nums[p+1]:
                                p += 1
                            while p < q and nums[q] == nums[q-1]:
                                q -= 1
                            p += 1
                            q -= 1
                        elif fSum < target:
                            p += 1
                        elif fSum > target:
                            q -= 1
        return res

    def quickSort(self, nums: List[int], lo: int, hi: int) -> None:
        def partition(lo: int, hi: int) -> int:
            v = nums[lo]
            i, j = lo + 1, hi
            while True:
                while i <= hi and nums[i] <= v:
                    i += 1
                    if i == hi:
                        break
                while nums[j] >= v:
                    j -= 1
                    if j == lo:
                        break
                if i >= j:
                    break
                tmp = nums[i]
                nums[i] = nums[j]
                nums[j] = tmp
            nums[lo] = nums[j]
            nums[j] = v
            return j
        
        if lo >= hi:
            return
        j = partition(lo, hi)
        self.quickSort(nums, lo, j-1)
        self.quickSort(nums, j+1, hi)


if __name__ == "__main__":
    s = Solution()
    nums = [5,5,3,5,1,-5,1,-2]
    print(s.fourSum(nums, 4))
    print(nums)
