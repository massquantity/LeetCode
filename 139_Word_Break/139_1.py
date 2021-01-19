from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        size = len(s)
        memo = [None] * size
        def dfs(start) -> bool:
            if start >= size:
                return True
            if memo[start] is not None:
                return memo[start]
            for j in range(start + 1, size + 1):
                if s[start: j] in wordSet and dfs(j):
                    memo[start] = True
                    return True
            memo[start] = False
            return False
        return dfs(0)
