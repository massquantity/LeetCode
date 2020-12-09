class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int m = nums1.length, n = nums2.length;
        int[] maxSubSequence = new int[k];
        int start = Math.max(0, k - n), end = Math.min(k, m);
        for (int i = start; i <= end; i++) {
            int[] subsequence1 = maxSubSequence(nums1, i);
            int[] subsequence2 = maxSubSequence(nums2, k - i);
            int[] curMaxSubsequence = merge(subsequence1, subsequence2);
            if (compare(curMaxSubsequence, 0, maxSubSequence, 0) > 0) {
                System.arraycopy(curMaxSubsequence, 0, maxSubSequence, 0, k);
            } 
        }
        return maxSubSequence;
    }

    private int[] maxSubSequence(int[] nums, int k) {
        int length = nums.length;
        int[] stack = new int[500];
        int top = -1;
        int keep = length - k;
        for (int n : nums) {
            while (top >= 0 && n > stack[top] && keep > 0) {
                top--;
                keep--;
            }
            stack[++top] = n;
        }
        int[] res = new int[k];
        System.arraycopy(stack, 0, res, 0, k);
        return res;
    }

    private int[] merge(int[] subsequence1, int[] subsequence2) {
        int m = subsequence1.length, n = subsequence2.length;
        if (m == 0) return subsequence2;
        if (n == 0) return subsequence1;
        int mergedLength = m + n;
        int[] merged = new int[mergedLength];
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergedLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    private int compare(int[] subsequence1, int index1, int[] subsequence2, int index2) {
        int m = subsequence1.length, n = subsequence2.length;
        while (index1 < m && index2 < n) {
            int diff = subsequence1[index1] - subsequence2[index2];
            if (diff != 0) return diff;
            index1++;
            index2++;
        }
        return (m - index1) - (n - index2);
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums1 = {3,4,6,5};
        int[] nums2 = {9,1,2,5,8,3};
        for (int n : s.maxNumber(nums1, nums2, 5)) {
            System.out.print(n + " ");
        }
        System.out.println();
    }
}
