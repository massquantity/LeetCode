from collections import deque
from typing import List, Dict

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        if numCourses == 0:
            return []
        
        adj = [set() for _ in range(numCourses)]
        inDegree = [0 for _ in range(numCourses)]
        for p in prerequisites:
            inDegree[p[0]] += 1
            adj[p[1]].add(p[0])

        queue = deque([])
        for i in inDegree:
            if i == 0:
                queue.append(i)
        
        res = []
        while queue:
            head = queue.popleft()
            res.append(head)
            successors = adj[head]
            for s in successors:
                inDegree[s] -= 1
                if inDegree[s] == 0:
                    queue.append(s)
        
        return res if len(res) == numCourses else []


if __name__ == "__main__":
    print(Solution().findOrder(4, [[1,0],[2,0],[3,1],[3,2]]))
