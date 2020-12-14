import java.util.Random;

class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        int i = new Random().nextInt(n);
        swap(nums, 0, i);
        quickSort(nums, 0, n - 1);
        return nums;
    }

    private void quickSort(int[] nums, int lo, int hi) {
        if (lo >= hi) return;
        int i = lo + 1, j = hi;
        while (true) {
            while (nums[i] <= nums[lo] && i < hi) i++;
            while (nums[j] > nums[lo] && j > lo) j--;
            if (i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        quickSort(nums, lo, j - 1);
        quickSort(nums, j + 1, hi);
    }

    private void quickSort2(int[] nums, int lo, int hi) {
        if (lo >= hi) return;
        int i = lo + 1, j = hi;
        while (true) {
            while (nums[i] <= nums[lo]) {
                i++;
                if (i > hi) break;
            }
            while (nums[j] > nums[lo]) {
                j--;
                if (j <= lo) break;
            }
            if (i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        quickSort(nums, lo, j - 1);
        quickSort(nums, j + 1, hi);
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
