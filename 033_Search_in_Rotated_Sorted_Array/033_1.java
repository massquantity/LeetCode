import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int search(int[] nums, int target) {
        int size = nums.length;
        if (size == 0) return -1;
        if (size == 1) return nums[0] == target ? 0 : -1;
        int lo = 0, hi = size;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (nums[mid] == target) return mid;
            else if (nums[lo] < nums[mid]) {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid;
                else
                    lo = mid + 1;
            } else {
                if (target > nums[mid] && target < nums[lo])
                    lo = mid + 1;
                else
                    hi = mid;
            }
        }
        return -1;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        System.out.println(s.search(nums, 7));
    }
}