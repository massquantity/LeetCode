from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        if not nums:
            return
        n = len(nums)
        j = n - 2
        while j >= 0 and nums[j] >= nums[j+1]:
            j -= 1
        if j >= 0:
            k = n - 1
            while k >= j and nums[k] <= nums[j]:
                k -= 1
            self.swap(nums, k, j)
        self.reverse(nums, j + 1, n - 1)

    def reverse(self, nums: List[int], i, j) -> None:
        while i < j:
            self.swap(nums, i, j)
            i += 1
            j -= 1

    def swap(self, nums: List[int], i, j) -> None:
        tmp = nums[i]
        nums[i] = nums[j]
        nums[j] = tmp