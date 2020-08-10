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
    public char firstUniqChar(String s) {
        Map<Character, Boolean> dic = new LinkedHashMap<>();
        char[] sc = s.toCharArray();
        for (char c : sc) {
            dic.put(c, !dic.containsKey(c));
        }
        for (Map.Entry<Character, Boolean> d : dic.entrySet()) {
            if (d.getValue()) return d.getKey();
        }
        return ' ';
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.firstUniqChar("leetcode"));
    }
}
