from typing import List, Dict
from queue import Queue
from collections import deque, Counter
import math
from heapq import heappush, heappushpop

class MaxQueue:
    def __init__(self):
        self.queue = deque()
        self.max_queue = deque()

    def max_value(self) -> int:
        return self.max_queue[0] if self.max_queue else -1

    def push_back(self, value: int) -> None:
        while self.max_queue and self.max_queue[-1] < value:
            self.max_queue.pop()
        self.max_queue.append(value)
        self.queue.append(value)

    def pop_front(self) -> int:
        if not self.queue:
            return -1
        val = self.queue.popleft()
        if val == self.max_queue[0]:
            self.max_queue.popleft()
        return val

