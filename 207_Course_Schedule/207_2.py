from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if not prerequisites:
            return True
        n = numCourses
        graph = [set() for _ in range(n)]
        visited = [0] * n
        for p in prerequisites:
            graph[p[1]].add(p[0])
            
        def dfs(i):
            if visited[i] == 1:
                return True
            if visited[i] == 2:
                return False
            visited[i] = 1
            for j in graph[i]:
                if dfs(j):
                    return True
            visited[i] = 2
            return False
            
        for i in range(n):
            if visited[i] == 0 and dfs(i):
                return False
        return True
