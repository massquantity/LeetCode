from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class Solution:
    def letterCombinations2(self, digits: str) -> List[str]:
        import itertools
        if not digits:
            return []

        phone_map = {
            '2': "abc", 
            '3': "def", 
            '4': "ghi", 
            '5': "jkl", 
            '6': "mno", 
            '7': "pqrs", 
            "8": "tuv",
            "9": "wxyz",
        }
        groups = (phone_map[d] for d in digits)
        return ["".join(comb) for comb in itertools.product(*groups)]


if __name__ == "__main__":
    s = Solution()
    print(s.letterCombinations2("23"))
