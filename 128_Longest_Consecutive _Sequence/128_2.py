from collections import deque, defaultdict
from typing import List, Dict

class UnionFind:
    def __init__(self, nums):
        self.parent = {n: n for n in nums}
        self.count = defaultdict(lambda: 1)
    def find(self, x):
        while x != self.parent[x]:
            x = self.parent[x]
        return x
    def union(self, x, y):
        if y not in self.parent:
            return 1
        root1 = self.find(x)
        root2 = self.find(y)
        if root1 == root2:
            return self.count[root1]
        self.parent[root2] = root1
        self.count[root1] += self.count[root2]
        return self.count[root1]

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        uf = UnionFind(nums)
        res = 1
        for n in nums:
            res = max(res, uf.union(n, n + 1))
        return res

    # optimized union-find
    def longestConsecutive2(self, nums: List[int]) -> int:
        parent = {n: n for n in nums}
        size = defaultdict(lambda: 1)
        def find(x):
            while x != parent[x]:
                x = parent[x]
                parent[x] = parent[parent[x]]
            return x
        
        def union(x, y):
            root1, root2 = find(x), find(y)
            if root1 == root2:
                return size[root1]
            if size[root1] < size[root2]:
                parent[root1] = root2
                size[root2] += size[root1]
                return size[root2]
            else:
                parent[root2] = root1
                size[root1] += size[root2]
                return size[root1]
        
        if not nums:
            return 0
        res = 1
        for n in nums:
            if n + 1 in parent:
                res = max(res, union(n, n + 1))
        return res


if __name__ == "__main__":
    print(Solution().longestConsecutive2([100,4,200,1,3,2]))
