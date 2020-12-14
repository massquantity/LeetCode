class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        for (int i = n / 2; i >= 0; i--) {
            maxHeapify(nums, i, n);
        }
        while (n > 0) {
            swap(nums, 0, n - 1);
            n--;
            maxHeapify(nums, 0, n);
        }
        return nums;
    }

    private void maxHeapify(int[] nums, int k, int n) {
        while (2*k + 1 < n) {
            int j = 2*k + 1;
            if (j < n - 1 && nums[j] < nums[j+1]) j++;
            if (nums[j] <= nums[k]) break;
            swap(nums, j, k);
            k = j;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

public class heapSort {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {5,2,3,1,-1,-34,45};
        s.sortArray(nums);
        for (int i : nums) 
            System.out.print(i + " ");
        System.out.println();
    }
}