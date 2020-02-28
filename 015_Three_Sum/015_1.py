from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        length = len(nums)
        if length < 3 or not nums:
            return []
        nums.sort();
        for i in range(length):
            if (nums[i] > 0):
                return res
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j = i + 1
            k = length - 1
            while j < k:
                if (nums[i] + nums[j] + nums[k]) == 0:
                    res.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    while j < k and nums[k] == nums[k - 1]:
                        k -= 1
                    j += 1
                    k -= 1
                elif nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                else:
                    j += 1
        return res

if __name__ == "__main__":
    nums = [-1,0,1,2,-1,-4]
    s = Solution()
    for r in s.threeSum(nums):
        print(r)