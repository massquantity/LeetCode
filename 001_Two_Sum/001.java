class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int other = target - nums[i];
            if (m.containsKey(other))
                return new int[] {m.get(other), i};
            else
                m.put(nums[i], i);
        }
        return new int[] {};
    }
}