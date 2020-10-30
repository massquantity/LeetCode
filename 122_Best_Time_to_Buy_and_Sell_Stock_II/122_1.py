class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        a, b = 0, float("-inf")
        for p in prices:
            b = max(b, a - p)
            a = max(a, b + p)
        return a