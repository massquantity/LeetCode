class Solution {
    private List<List<Integer>> res;
    private Deque<Integer> tmp;

    public List<List<Integer>> combine(int n, int k) {
        res = new ArrayList<>();
        tmp = new LinkedList<>();
        dfs(n, k, 1);
        return res;
    }

    public void dfs(int n, int k, int index) {
        if (tmp.size() == k) {
            res.add(new ArrayList(tmp));
            return;
        }

        // for (int i = index; i <= n; i++)
        for (int i = index; i <= n - (k - tmp.size()) + 1; i++) {
            tmp.add(i);
            dfs(n, k, i + 1);
            tmp.removeLast();
        }
    }
}