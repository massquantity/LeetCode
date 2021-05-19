class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for n in nums:
            i = abs(n) - 1
            if nums[i] > 0:
                nums[i] = -nums[i]
        return [i + 1 for i, n in enumerate(nums) if n > 0]
