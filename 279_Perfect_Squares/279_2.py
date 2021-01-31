class Solution:
    def numSquares(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        res = float("inf")
        def dfs(i, count, num):
            nonlocal res
            if num == 0:
                res = min(res, count)
                return
            if num < 0:
                return
            for j in range(i, n):
                if i*i > n:
                    break
                dfs(j, count + 1, num - j*j)            

        dfs(1, 0, n)
        return res
