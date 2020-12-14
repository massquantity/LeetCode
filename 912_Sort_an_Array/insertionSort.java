class Solution {
    public int[] sortArray(int[] nums) {
        insertionSort(nums, nums.length);
        return nums;
    }

    private void insertionSort(int[] nums, int len) {
        for (int i = 1; i < len; i++) {
            int tmp = nums[i], j = i;
            while (j > 0 && tmp < nums[j-1]) {
                nums[j] = nums[j-1];
                j--;
            }
            nums[j] = tmp;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {5,2,3,1,-1,-34,45};
        s.sortArray(nums);
        for (int i : nums) 
            System.out.print(i + " ");
        System.out.println();
    }
}
