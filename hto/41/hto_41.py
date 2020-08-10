from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop


class MedianFinder:
    def __init__(self):
        self.min_heap = []
        self.max_heap = []
    def addNum(self, num: int) -> None:
        if len(self.min_heap) != len(self.max_heap):
            heappush(self.max_heap, -heappushpop(self.min_heap, num))
        else:
            heappush(self.min_heap, -heappushpop(self.max_heap, -num))

    def findMedian(self) -> float:
        return self.min_heap[0] if len(self.min_heap) != len(self.max_heap) else (self.min_heap[0] - self.max_heap[0]) / 2.0

if __name__ == "__main__":
    aa = [1,2,3,2,2,2,5,4,2]
    s = MedianFinder()
    s.addNum(1)
    s.addNum(2)
    print(s.findMedian())
    s.addNum(3)
    print(s.findMedian())
