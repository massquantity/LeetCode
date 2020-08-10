from typing import List, Dict
from queue import Queue
from collections import deque

def digitSum(m):
    res = 0
    while m:
        res += m % 10
        m //= 10
    return res

class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        q = deque()
        q.append((0, 0))
        visited = set()
        while q:
            x, y = q.popleft()
            if (x, y) in visited or x >= m or y >= n or digitSum(x) + digitSum(y) > k:
                continue
            visited.add((x, y))
            for nx, ny in ((x + 1, y), (x, y + 1)):
                q.append((nx, ny))
        return len(visited)

class Solution1:
    def movingCount(self, m: int, n: int, k: int) -> int:
        q = Queue()
        q.put((0, 0))
        visited = set()
        while not q.empty():
            x, y = q.get()
            if (x, y) in visited or x >= m or y >= n or digitSum(x) + digitSum(y) > k:
                continue
            visited.add((x, y))
            for nx, ny in ((x + 1, y), (x, y + 1)):
                q.put((nx, ny))
        return len(visited)


if __name__ == "__main__":
    s = Solution()
    print(s.movingCount(2, 3, 1))