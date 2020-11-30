from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        tmp = []
        def dfs(cur):
            if len(tmp) == k:
                res.append(tmp[:])
                return
            for i in range(cur, n + 1):
                tmp.append(i)
                dfs(i+1)
                tmp.pop()
        dfs(1)
        return res


if __name__ == "__main__":
    s = Solution()
    print(s.combine(4, 2))
