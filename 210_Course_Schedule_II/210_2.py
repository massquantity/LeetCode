from typing import List, Dict

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        if numCourses == 0:
            return []
        if not prerequisites:
            return list(reversed(range(numCourses)))

        valid = True
        stack = []
        graph = [[] for _ in range(numCourses)]
        visited = [0 for _ in range(numCourses)]
        for p in prerequisites:
            graph[p[1]].append(p[0])

        def dfs(index) -> None:
            nonlocal valid
            visited[index] = 1
            for v in graph[index]:
                if visited[v] == 0:
                    dfs(v)
                    if not valid:
                        return
                elif visited[v] == 1:
                    valid = False
                    return
            
            visited[index] = 2
            stack.append(index)

        for i in range(numCourses):
            if valid and visited[i] == 0:
                dfs(i)
        if not valid:
            return []
        return stack[::-1]

if __name__ == "__main__":
    print(Solution().findOrder(4, [[1,0],[2,0],[3,1],[3,2]]))
