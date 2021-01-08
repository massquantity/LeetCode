from typing import List

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        parents = [i for i in range(n)]
        sizes = [1 for i in range(n)]
        count = n

        def find(x):
            while x != parents[x]:
                x = parents[x]
                parents[x] = parents[parents[x]]
            return x
        
        def union(i, j):
            nonlocal count
            root1 = find(i)
            root2 = find(j)
            if root1 == root2:
                return
            if sizes[root1] < sizes[root2]:
                parents[root1] = root2
                sizes[root2] += sizes[root1]
            else:
                parents[root2] = root1
                sizes[root1] += sizes[root2]
            count -= 1

        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j] == 1:
                    union(i, j)
        return count
