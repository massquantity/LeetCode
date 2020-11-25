from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        if not nums:
            return

        left, right = 0, len(nums)
        i = 0
        while i < right:
            if nums[i] == 0:
                nums[left], nums[i] = nums[i], nums[left]
                left += 1
                i += 1
            elif nums[i] == 2:
                right -= 1
                nums[right], nums[i] = nums[i], nums[right]
            else:
                i += 1

        return nums