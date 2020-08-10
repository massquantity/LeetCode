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

class Solution {
    public String minNumber(int[] nums) {
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strs[i] = String.valueOf(nums[i]);
        }
        fastSort(strs, 0, strs.length - 1);
        StringBuilder res = new StringBuilder();
        for (String s : strs) {
            res.append(s);
        }
        return res.toString();
    }

    private void fastSort(String[] strs, int lo, int hi) {
        if (lo >= hi) return;
        String v = strs[lo];
        int i = lo, j = hi + 1;
        while (true) {
            while (++i < hi && (strs[i] + strs[lo]).compareTo(strs[lo] + strs[i]) <= 0);
            while (--j > lo && (strs[j] + strs[lo]).compareTo(strs[lo] + strs[j]) >= 0);
            if (i >= j) break;
            String tmp = strs[i];
            strs[i] = strs[j];
            strs[j] = tmp;
        }
        strs[lo] = strs[j];
        strs[j] = v;
        fastSort(strs, j + 1, hi);
        fastSort(strs, lo, j - 1);
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[] array = {3,30,34,5,9};
        Solution s = new Solution();
        System.out.println(s.minNumber(array));
    }
}
