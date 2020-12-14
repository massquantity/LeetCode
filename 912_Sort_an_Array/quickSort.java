import java.util.Random;

class Solution {
    private int[] aux;
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        Random r = new Random();
        int i = r.nextInt(n);
        swap(nums, 0, i);
        quickSort(nums, 0, n - 1);
        return nums;
    }

    private void quickSort(int[] nums, int lo, int hi) {
        if (lo >= hi) return;
        int last = lo, i;
        for (i = last + 1; i <= hi; i++) {
            if (nums[i] < nums[lo]) {
                swap(nums, ++last, i);
            }
        }
        swap(nums, lo, last);

        quickSort(nums, lo, last - 1);
        quickSort(nums, last + 1, hi);
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

public class quickSort {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {5,2,3,1,-1,-34,45};
        s.sortArray(nums);
        for (int i : nums) 
            System.out.print(i + " ");
        System.out.println();
    }
}
