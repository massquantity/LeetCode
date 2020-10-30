class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pre, a, b = 0, 0, float("-inf")
        for p in prices:
            tmp = a
            a = max(a, b + p)
            b = max(b, pre - p)
            pre = tmp
        return a