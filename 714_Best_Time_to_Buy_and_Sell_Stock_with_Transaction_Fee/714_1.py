class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        a, b = 0, float("-inf")
        for p in prices:
            b = max(b, a - p - fee)
            a = max(a, b + p)
        return a