from typing import List, Dict
from functools import lru_cache

class Solution:
    @lru_cache(None)
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        return (self.fib(n-1)+self.fib(n-2)) % 1000000007


if __name__ == "__main__":
    s = Solution()
    print(s.fib(95))