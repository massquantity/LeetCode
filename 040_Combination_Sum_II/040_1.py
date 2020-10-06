from typing import List, Dict

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        tmp = []
        candidates.sort()

        def dfs(tmp, target, start):
            if target < 0: 
                return
            if target == 0:
                res.append(tmp)
                return
            
            for i in range(start, len(candidates)):
                if target < candidates[i]:
                    break
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                dfs(tmp + [candidates[i]], target - candidates[i], i + 1)
        
        dfs(tmp, target, 0)
        return res
