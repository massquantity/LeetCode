from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        num_set = set(nums)
        for n in nums:
            if n - 1 not in num_set:
                cur = n
                cur_len = 1
                while cur + 1 in num_set:
                    cur += 1
                    cur_len += 1
                res = max(res, cur_len)
        return res
