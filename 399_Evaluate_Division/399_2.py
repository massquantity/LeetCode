class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = collections.defaultdict(set)
        weights = dict()
        visited = set()

        def bfs(start, end):
            if (start, end) in weights:
                return weights[(start, end)]
            if start not in graph or end not in graph:
                return -1.0
            if start == end:
                return 1.0
            visited.add(start)
            queue = collections.deque()
            for n in graph[start]:
                queue.append((n, weights[(start, n)]))
            while queue:
                n, w = queue.popleft()
                if n == end:
                    return w
                for neig in graph[n]:
                    if neig not in visited:
                        visited.add(neig)
                        weights[(start, neig)] = w * weights[(n, neig)]
                        queue.append((neig, weights[(start, neig)]))
            return -1.0

        for g, v in zip(equations, values):
            graph[g[0]].add(g[1])
            graph[g[1]].add(g[0])
            weights[(g[0], g[1])] = v
            weights[(g[1], g[0])] = 1.0 / v
        
        res = list()
        for q in queries:
            visited.clear()
            res.append(bfs(q[0], q[1]))
        return res
