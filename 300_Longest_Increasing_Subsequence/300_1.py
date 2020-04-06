from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        length = len(nums)
        dp = [1] * length
        for i in range(length):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)

        res = 1
        for i in range(length):
            res = max(res, dp[i])
        return res


if __name__ == "__main__":
    s = Solution()
    a = [10, 9, 2, 5, 3, 7, 101, 18]
    print(s.lengthOfLIS(a))