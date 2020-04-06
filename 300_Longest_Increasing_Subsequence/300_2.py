from typing import List

# https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        length = len(nums)
        maxL = 0
        dp = [0] * length
        for num in nums:
            lo, hi = 0, maxL
            while lo < hi:
                mid = (lo + hi) // 2
                if dp[mid] < num:
                    lo = mid + 1
                else:
                    hi = mid
            dp[lo] = num
            if lo == maxL:
                maxL += 1
        return maxL


if __name__ == "__main__":
    s = Solution()
    a = [10, 9, 2, 5, 3, 7, 101, 18]
    print(s.lengthOfLIS(a))