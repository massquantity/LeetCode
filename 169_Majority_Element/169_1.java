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

class Solution {
    public int majorityElement(int[] nums) {
        if (nums.length == 1) return nums[0];
        Map<Integer, Integer> map = new HashMap<>();
        int halfLength = nums.length / 2 + 1;
        for (int n : nums) {
            if (!map.containsKey(n)) {
                map.put(n, 1);
            } else {
                int count = map.get(n);
                if (count + 1 >= halfLength) {
                    return n;
                } else {
                    map.put(n, count + 1);
                }
            }
        }
        return 0;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] aa = {1, 2, 3, 2, 2, 2, 5, 4, 2};
        System.out.println(s.majorityElement(aa));
    }
}


