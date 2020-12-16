from functools import lru_cache
from typing import List, Dict

class Solution:
    @lru_cache(None)
    def isScramble(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        letters = [0 for _ in range(26)]
        for i in range(len(s1)):
            letters[ord(s1[i]) - ord('a')] += 1
            letters[ord(s2[i]) - ord('a')] -= 1
        if any(letters):
            return False
        
        for i in range(1, len(s1)):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i]):
                return True
        
        return False


if __name__ == "__main__":
    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    print(Solution().isScramble("great", "rgeat"))
