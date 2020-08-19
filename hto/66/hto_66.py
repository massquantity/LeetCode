from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        if not a:
            return a
        
        length = len(a)
        left = [0] * length
        right = [0] * length
        left[0] = right[length-1] = 1
        for i in range(1, length):
            left[i] = left[i-1] * a[i-1]
        for i in reversed(range(length-1)):
            right[i] = right[i+1] * a[i+1]
        
        res = [0] * length
        for i in range(length):
            res[i] = left[i] * right[i]
        
        return res