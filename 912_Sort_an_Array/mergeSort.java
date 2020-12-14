class Solution {
    private int[] aux;
    public int[] sortArray(int[] nums) {
        aux = new int[nums.length];
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }

    private void mergeSort(int[] nums, int lo, int hi) {
        if (hi <= lo) return;
        int mid = (lo + hi) >>> 1;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }

    private void merge(int[] nums, int lo, int mid, int hi) {
        for (int k = lo; k <= hi; k++) {
            aux[k] = nums[k];
        }

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)         nums[k] = aux[j++];
            else if (j > hi)          nums[k] = aux[i++];
            else if (aux[i] < aux[j]) nums[k] = aux[i++];
            else                      nums[k] = aux[j++];
        }
    }

    private void merge2(int[] nums, int lo, int mid, int hi) {
        for (int k = lo; k <= hi; k++) {
            aux[k] = nums[k];
        }

        int i = lo, j = mid + 1, k = lo;
        while (i <= mid && j <= hi) {
            if (aux[i] < aux[j])  nums[k++] = aux[i++];
            else                  nums[k++] = aux[j++];
        }
        while (i <= mid)  nums[k++] = aux[i++];
        while (j <= hi)   nums[k++] = aux[j++];
    }
}

public class mergeSort {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {5,2,3,1,-1,-34,45};
        s.sortArray(nums);
        for (int i : nums) 
            System.out.print(i + " ");
        System.out.println();
    }
}
