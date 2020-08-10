from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binarySearch(nums: List[int], target: int):
            lo, hi = 0, len(nums)
            while lo < hi:
                mid = (lo + hi) >> 1
                if target <= nums[mid]:
                    hi = mid
                else:
                    lo = mid + 1
            return lo

        start = binarySearch(nums, target)
        end = binarySearch(nums, target + 1)
        if start == len(nums) or nums[start] != target:
            return 0
        else:
            return end - start


if __name__ == "__main__":
    arr = [5,7,7,8,8,10]
    s = Solution()
    print(s.search(arr, 8))
