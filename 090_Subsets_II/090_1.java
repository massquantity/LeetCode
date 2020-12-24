class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int size = nums.length;
        if (size == 0) {
            res.add(new ArrayList<>());
            return res;
        }
        Arrays.sort(nums);
        List<Integer> tmp = new ArrayList<>();
        dfs(nums, res, tmp, 0);
        return res;
    }

    private void dfs(int[] nums, List<List<Integer>> res, List<Integer> tmp, int idx) {
        res.add(new ArrayList<>(tmp));
        for (int i = idx; i < nums.length; i++) {
            if (i > idx && nums[i] == nums[i-1]) continue;
            tmp.add(nums[i]);
            dfs(nums, res, tmp, i + 1);
            tmp.remove(tmp.size() - 1);
        }
    }
}
