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
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Random;

class Solution {
    public int longestConsecutive(int[] nums) {
        int res = 0;
        Map<Integer, Integer> dict = new HashMap<>();
        for (int n : nums) {
            if (!dict.containsKey(n)) {
                int left  = dict.getOrDefault(n - 1, 0);
                int right = dict.getOrDefault(n + 1, 0);
                int cur = 1 + left + right;
                if (cur > res) res = cur;
                dict.put(n, cur);
                dict.put(n - left, cur);
                dict.put(n + right, cur);
            }
        }
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {100,4,200,1,3,2};
        System.out.println(s.longestConsecutive(nums));
    }
}
