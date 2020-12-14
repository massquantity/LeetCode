class Solution {
    public int[] sortArray(int[] nums) {
        shellSort(nums, nums.length);
        return nums;
    }

    private void shellSort(int[] nums, int len) {
        int h = 1;
        while (h < len / 2) h = 3*h + 1;
        while (h >= 1) {
            for (int i = h; i < len; i++) {
                for (int j = i; j >= h && nums[j] < nums[j-1]; j -= h) {
                    swap(nums, j, j - h);
                }
            }
            h /= 3;
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
