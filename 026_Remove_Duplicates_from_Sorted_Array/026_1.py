from typing import List, Dict

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        res = 0
        i, j = 0, 0
        while i < len(nums):
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            nums[j] = nums[i]
            j += 1
            i += 1
            res += 1
        return res