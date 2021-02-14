class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        sum_ = sum(nums)
        if S > sum_:
            return 0
        if (S + sum_) % 2 != 0:
            return 0
        target = (S + sum_) // 2
        dp = [0] * (target + 1)
        dp[0] = 1
        for n in nums:
            for i in range(target, n - 1, -1):
                dp[i] += dp[i - n]
        return dp[target]
