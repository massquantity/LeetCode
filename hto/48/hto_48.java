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
    public int lengthOfLongestSubstring(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        int res = 0, i = 0, j = 0;
        while (i < s.length() && j < s.length()) {
            if (!dq.contains(s.charAt(j))) {
                dq.add(s.charAt(j++));
                res = Math.max(res, j - i);
            } else {
                dq.removeFirst();
                i++;
            }
        }
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.lengthOfLongestSubstring("abcabcbb"));
    }
}


