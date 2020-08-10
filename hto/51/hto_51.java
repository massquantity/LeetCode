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

class Solution {
    private int[] aux;
    public int reversePairs(int[] nums) {
        if (nums.length < 2) return 0;
        aux = new int[nums.length];
        return mergePairs(nums, 0, nums.length - 1);
    }

    private int mergePairs(int[] nums, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = (lo + hi) >>> 1;
        int leftPairs = mergePairs(nums, lo, mid);
        int rightPairs = mergePairs(nums, mid+1, hi);
        if (nums[mid] <= nums[mid+1]) return leftPairs + rightPairs;
        int crossPairs = merge(nums, lo, mid, hi);
        return leftPairs + rightPairs + crossPairs;
    }

    private int merge(int[] nums, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) {
            aux[i] = nums[i];
        }
        int count = 0;
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid)               nums[k] = aux[j++];
            else if (j > hi)           nums[k] = aux[i++];
            else if (aux[i] <= aux[j]) nums[k] = aux[i++];
            else {
                count += (mid - i + 1);
                nums[k] = aux[j++];
            }
        }
        return count;
    }
}
public class leetcode {
    public static void main(String[] args) {
        int[] arr = {7,5,6,4};
        Solution s = new Solution();
        System.out.println(s.reversePairs(arr));
    }
}
