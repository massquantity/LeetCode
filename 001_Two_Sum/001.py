class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = dict()
        for i, n in enumerate(nums):
            other = target - n
            if other in res:
                return [res[other], i]
            else:
                res[n] = i
        return []