class Solution {
    public int maxProduct(int[] nums) {
        int res = nums[0];
        int max = nums[0], min = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int n = nums[i];
            int tmp_min = min * n;
            int tmp_max = max * n;
            max = Math.max(n, Math.max(tmp_min, tmp_max));
            min = Math.min(n, Math.min(tmp_max, tmp_min));
            res = Math.max(res, max);
        }
        return res;
    }
}
