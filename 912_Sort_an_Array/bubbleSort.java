class Solution {
    public int[] sortArray(int[] nums) {
        bubbleSort2(nums, nums.length);
        return nums;
    }

    private void bubbleSort(int[] nums, int len) {
        for (int i = len - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums, j, j+1);
                }
            }
        }
    }

    private void bubbleSort2(int[] nums, int len) {
        for (int i = len - 1; i > 0; i--) {
            Boolean sorted = true;
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j+1]) {
                    sorted = false;
                    swap(nums, j, j+1);
                }
            }
            if (sorted) break;
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
