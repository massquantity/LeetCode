from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        prefix, suffix = 1, 1
        for i in range(n):
            res[i] *= prefix
            res[n-1-i] *= suffix
            prefix *= nums[i]
            suffix *= nums[n-1-i]
        return res
