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
            
        valid = True
        def dfs(i):
            nonlocal valid
            visited[i] = 1
            for j in graph[i]:
                if visited[j] == 0:
                    dfs(j)
                    if not valid:
                        return False
                elif visited[j] == 1:
                    valid = False
                    return
            visited[i] = 2
            
        for i in range(n):
            if visited[i] == 0:
                dfs(i)
                if not valid:
                    return False
        return True
