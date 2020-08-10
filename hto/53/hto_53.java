import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.LinkedHashMap;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int search(int[] nums, int target) {
        int start = binarySearch(nums, target);
        int end = binarySearch(nums, target + 1);
        if (start == nums.length || nums[start] != target) return 0;
        return end - start;
    }

    private int binarySearch(int[] nums, int target) {
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
        System.out.println(s.search(nums, 8));
    }
}

