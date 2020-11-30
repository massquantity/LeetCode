class Solution {
    private List<List<Integer>> res;
    private Deque<Integer> tmp;

    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        tmp = new LinkedList<>();
        res.add(new ArrayList<>());
        dfs(nums, 0);
        return res;
    }

    public void dfs(int[] nums, int index) {
        if (index == nums.length) return;
        for (int i = index; i < nums.length; i++) {
            tmp.add(nums[i]);
            res.add(new ArrayList(tmp));
            dfs(nums, i + 1);
            tmp.removeLast();
        }
    }
}