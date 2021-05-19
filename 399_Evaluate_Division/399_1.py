class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = collections.defaultdict(set)
        weights = dict()
        visited = set()

        def dfs(start, end):
            if (start, end) in weights:
                return weights[(start, end)]
            if start not in graph or end not in graph:
                return 0.0
            if start in visited:
                return 0.0
            visited.add(start)
            res = 0.0
            for node in graph[start]:
                res = dfs(node, end) * weights[(start, node)]
                if res != 0.0:
                    weights[(start, end)] = res
                    break
            visited.remove(start)
            return res

        for g, v in zip(equations, values):
            graph[g[0]].add(g[1])
            graph[g[1]].add(g[0])
            weights[(g[0], g[1])] = v
            weights[(g[1], g[0])] = 1.0 / v
        
        res = list()
        for q in queries:
            visited.clear()
            num = dfs(q[0], q[1])
            res.append(-1.0 if num == 0.0 else num)
        return res
