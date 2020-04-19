import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start = search(nums, target);
        int end = search(nums, target + 1);
        if (start == nums.length || nums[start] != target)   // prevent start = nums.length, array out of bounds
            return new int[]{-1, -1};
        return new int[]{start, end - 1};
    }

    private int search(int[] nums, int target) {
        int lo = 0, hi = nums.length;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (target <= nums[mid])
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[] nums = {5, 7, 7, 8, 8, 10};
        Solution s = new Solution();
        System.out.println(s.searchRange(nums, 8)[0]);
    }
}