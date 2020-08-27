from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = nums[0] + nums[1] + nums[2]
        length = len(nums)
        for i in range(length - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j, k = i + 1, length - 1
            while j < k:
                cur = nums[i] + nums[j] + nums[k]
                if abs(cur - target) < abs(res - target):
                    res = cur
                if cur == target:
                    return res
                elif cur < target:
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                elif cur > target:
                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
        return res