class Solution {
    public int[] twoSum(int[] nums, int target) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (!set.contains(target - num))
                set.add(num);
            else 
                return new int[]{num, target - num};
        }
        return new int[]{};
    }
}