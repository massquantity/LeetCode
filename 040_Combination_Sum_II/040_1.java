class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Deque<Integer> tmp = new LinkedList<>();
        Arrays.sort(candidates);
        dfs(res, tmp, candidates, target, 0);
        return res;
    }

    private void dfs(List<List<Integer>> res, Deque<Integer> tmp, int[] candidates, int target, int start) {
        if (target < 0) return;
        if (target == 0) {
            res.add(new ArrayList<>(tmp));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (target < candidates[i]) break;
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            tmp.add(candidates[i]);
            dfs(res, tmp, candidates, target - candidates[i], i + 1);
            tmp.removeLast();
        }
    }
}
