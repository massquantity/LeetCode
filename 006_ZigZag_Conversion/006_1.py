from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s or s == "" or numRows < 1:
            return ""
        if numRows == 1:
            return s
        tmp = [[] for _ in range(numRows)]
        for i in range(len(s)):
            ans = i // (numRows - 1)
            cur = i %  (numRows - 1)
            if ans % 2 == 0:
                tmp[cur].append(s[i])
            else:
                tmp[numRows - 1 - cur].append(s[i])
        res = []
        for i in range(numRows):
            res.append("".join(tmp[i]))
        return "".join(res)


if __name__ == "__main__":
    s = Solution()
    str_ = "LEETCODEISHIRING"
    print(s.convert(str_, 4))
