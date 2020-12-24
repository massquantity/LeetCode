from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        tmp = []

        def dfs(tmp, index):
            res.append(tmp[:])
            for i in range(index, len(nums)):
                if i > index and nums[i-1] == nums[i]:
                    continue
                tmp.append(nums[i])
                dfs(tmp, i + 1)
                tmp.pop()

        dfs(tmp, 0)
        return res