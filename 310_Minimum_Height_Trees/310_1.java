class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if (n == 1) {
            res.add(0);
            return res;
        }
        Deque<Integer> queue = new ArrayDeque<>();
        List<List<Integer>> graph = new ArrayList<>();
        int[] degree = new int[n];
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                queue.offerLast(i);
        }

        while (!queue.isEmpty()) {
            res = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int cur = queue.pollFirst();
                res.add(cur);
                List<Integer> adj = graph.get(cur);
                for (Integer k : adj) {
                    degree[k]--;
                    if (degree[k] == 1)
                        queue.offerLast(k);
                }
            }
        }
        return res;
    }
}
