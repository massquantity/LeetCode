from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        left, right = 1, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            cnt = 0
            for n in nums:
                if n <= mid:
                    cnt += 1
            
            if cnt <= mid:
                left = mid + 1
            else:
                right = mid
        return left
