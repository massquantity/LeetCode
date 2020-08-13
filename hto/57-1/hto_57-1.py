from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop


class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i, j = 1, 2
        res = []
        sum_ = 3
        while j <= target // 2 + 1:
            if sum_ == target:
                res.append(list(range(i, j + 1)))
                i += 1
                j = i + 1
                sum_ = i + j
            elif sum_ < target:
                j += 1
                sum_ += j
            elif sum_ > target:
                sum_ -= i
                i += 1
        return res


if __name__ == "__main__":
    s = Solution()
    print(s.findContinuousSequence(15))
