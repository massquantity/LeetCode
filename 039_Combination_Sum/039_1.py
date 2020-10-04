from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(tmp, target, begin):
            if target < 0:
                return
            if target == 0:
                res.append(tmp)
                return
            for i in range(begin, len(candidates)):
                if target < candidates[i]:
                    break
                dfs(tmp + [candidates[i]], target - candidates[i], i)

        candidates.sort()
        tmp = []
        res = []
        dfs(tmp, target, 0)
        return res


if __name__ == "__main__":
    s = Solution()
    candidates = [2,3,6,7]
    target = 7
    print(s.combinationSum(candidates, target))
