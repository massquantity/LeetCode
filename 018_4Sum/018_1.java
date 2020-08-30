class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int len = nums.length;
        if (nums == null || len < 4) return res;
        Arrays.sort(nums);
        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j == i + 1 || j > i + 1 && nums[j - 1] < nums[j]) {
                    int p = j + 1, q = len - 1;
                    while (p < q) {
                        int fSum = nums[i] + nums[j] + nums[p] + nums[q];
                        if (fSum == target) {
                            res.add(Arrays.asList(nums[i], nums[j], nums[p], nums[q]));
                            while (p < q && nums[p] == nums[p + 1]) p++;;
                            p++;
                            while (p < q && nums[q] == nums[q - 1]) q--;
                            q--; 
                        }
                        else if (fSum < target) p++;
                        else if (fSum > target) q--;
                    }
                } 
            }
        }
        return res;
    }
}