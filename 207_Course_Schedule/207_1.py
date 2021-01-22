from collection import deque
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if not prerequisites:
            return True
        n = numCourses
        graph = [set() for _ in range(n)]
        in_degree = [0] * n
        for p in prerequisites:
            graph[p[1]].add(p[0])
            in_degree[p[0]] += 1
        
        queue = deque([])
        for i in range(n):
            if in_degree[i] == 0:
                queue.append(i)
        
        count = 0
        while queue:
            tmp = queue.popleft()
            count += 1
            if count == n:
                return True
            for j in graph[tmp]:
                in_degree[j] -= 1
                if in_degree[j] == 0:
                    queue.append(j)
        return False
