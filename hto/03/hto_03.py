from typing import List

class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while nums[i] != i:
                if nums[i] == nums[nums[i]]:
                    return nums[i]
                tmp = nums[i]
                nums[i], nums[tmp] = nums[tmp], nums[i]

