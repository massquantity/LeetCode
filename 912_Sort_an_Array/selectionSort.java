class Solution {
    public int[] sortArray(int[] nums) {
        selectionSort(nums, nums.length);
        return nums;
    }

    private void selectionSort(int[] nums, int len) {
        for (int i = 0; i < len; i++) {
            int min = i;
            for (int j = i + 1; j < len; j++) {
                if (nums[j] < nums[min]) min = j;
            }
            swap(nums, i, min);
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
