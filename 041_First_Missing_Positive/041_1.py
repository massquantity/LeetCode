from typing import List, Dict

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        size = len(nums)
        for i in range(size):
            while 0 <= nums[i] - 1 < size and nums[i] != nums[nums[i] - 1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
                # if expression is: nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i] will cause error!

        for i in range(size):
            if i + 1 != nums[i]:
                return i + 1
        return size + 1

