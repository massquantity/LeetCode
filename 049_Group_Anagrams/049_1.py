from typing import List, Dict
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for s in strs:
            res[str(sorted(s))].append(s)
        return list(res.values())
        

if __name__ == "__main__":
    s = Solution()
    print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
