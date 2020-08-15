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
import java.util.Comparator;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || k == 0) return new int[0];
        int[] res = new int[nums.length - k + 1];
        Deque<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < k - 1; i++) {
            while (!queue.isEmpty() && queue.peekLast() < nums[i])
                queue.pollLast();
            queue.offer(nums[i]); 
        }
        for (int i = k - 1, j = 0; i < nums.length; i++) {
            while (!queue.isEmpty() && queue.peekLast() < nums[i]) 
                queue.pollLast();
            queue.offer(nums[i]);
            res[j++] = queue.peek();
            if (!queue.isEmpty() && queue.peek() == nums[i - k + 1]) 
                queue.poll();
        }
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[] nums = {1,3,-1,-3,5,3,6,7};
        Solution s = new Solution();
        System.out.println(Arrays.toString(s.maxSlidingWindow(nums, 3)));
    }
}


