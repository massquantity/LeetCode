from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        phone_map = {
            '2': "abc", 
            '3': "def", 
            '4': "ghi", 
            '5': "jkl", 
            '6': "mno", 
            "8": "tuv",
            "9": "wxyz",
        }
        res = []
        combination = ""
        def backtrack(index, comb):
            if index == len(digits):
                res.append(comb)
                return
            letters = phone_map[digits[index]]
            for letter in letters:
                backtrack(index + 1, comb + letter)
        backtrack(0, combination)
        return res


if __name__ == "__main__":
    s = Solution()
    print(s.letterCombinations("23"))
