from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        size = len(s)
        import functools
        @functools.lru_cache(None)
        def dfs(start) -> bool:
            if start >= size:
                return True
            for j in range(start + 1, size + 1):
                if s[start: j] in wordSet and dfs(j):
                    return True
            return False
        return dfs(0)
