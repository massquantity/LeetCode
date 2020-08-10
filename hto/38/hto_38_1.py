from typing import List, Dict
from queue import Queue
from collections import deque
import math
import itertools

class Solution:
    def permutation(self, s: str) -> List[str]:
        c, res = list(s), []
        def dfs(pos):
            if pos == len(s) - 1:
                res.append("".join(c))
                return
            set_ = set()
            for i in range(pos, len(c)):
                if c[i] in set_:
                    continue
                set_.add(c[i])
                c[i], c[pos] = c[pos], c[i]
                dfs(pos + 1)
                c[i], c[pos] = c[pos], c[i]
        dfs(0)
        return res


if __name__ == "__main__":
    ss = "abc"
    s = Solution()
    print(s.permutation(ss))
