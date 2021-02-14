from typing import List

class Solution:  # 超时
    def coinChange(self, coins: List[int], amount: int) -> int:
        res = float("inf")
        coins.sort(reverse=True)

        def dfs(sum_, count):
            nonlocal res
            if sum_ == amount:
                res = min(res, count)
            elif sum_ > amount:
                return
            for coin in coins:
                dfs(sum_ + coin, count + 1)

        dfs(0, 0)
        return -1 if res == float("inf") else res
