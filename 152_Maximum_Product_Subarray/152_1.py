from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        max_num, min_num = nums[0], nums[0]
        for i in range(1, len(nums)):
            tmp_max, tmp_min = max_num * nums[i], min_num * nums[i]
            max_num = max(nums[i], tmp_max, tmp_min)
            min_num = min(nums[i], tmp_min, tmp_max)
            res = max(res, max_num)
        return res
