from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cost, profit = float("inf"), 0
        for price in prices:
            cost = min(cost, price)
            profit = max(profit, price - cost)
        return profit