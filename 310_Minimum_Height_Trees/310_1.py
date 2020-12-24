from collections import deque
from typing import List, Dict

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]

        degree = [0] * n
        graph = [[] for _ in range(n)]
        for e in edges:
            degree[e[0]] += 1
            degree[e[1]] += 1
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        
        queue = deque()
        for i in range(n):
            if degree[i] == 1:
                queue.append(i)
        
        while queue:
            res = []
            size = len(queue)
            for i in range(size):
                cur = queue.popleft()
                res.append(cur)
                adj = graph[cur]
                for k in adj:
                    degree[k] -= 1
                    if degree[k] == 1:
                        queue.append(k)
        
        return res


if __name__ == "__main__":
    print(Solution().findMinHeightTrees(7, [[0,1],[1,2],[1,3],[2,4],[3,5],[4,6]]))
