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

class Solution {
    public String minWindow(String s, String t) {
        int sLen = s.length();
        int tLen = t.length();
        if (sLen == 0 || tLen == 0 || sLen < tLen) return "";

        char[] charArrayS = s.toCharArray();
        char[] charArrayT = t.toCharArray();
        int[] windowFreq = new int[128];
        int[] tFreq = new int[128];
        for (char c : charArrayT) {
            tFreq[c]++;
        }

        int distance = 0, minLen = sLen + 1, begin = 0;
        int left = 0, right = 0;
        while (right < sLen) {
            char c_right = charArrayS[right];
            if (tFreq[c_right] == 0) {
                right++;
                continue;
            }
            if (windowFreq[c_right] < tFreq[c_right]) distance++;
            windowFreq[c_right]++;
            right++;

            while (distance == tLen) {
                if (right - left < minLen) {
                    begin = left;
                    minLen = right - left;
                }

                char c_left = charArrayS[left];
                if (tFreq[c_left] == 0) {
                    left++;
                    continue;
                }
                if (windowFreq[c_left] == tFreq[c_left]) distance--;
                windowFreq[c_left]--;
                left++;
            }
        }
        return minLen == sLen + 1 ? "" : s.substring(begin, begin + minLen);
    }
}

public class leetcode {
    public static void main(String[] args) {
    //    System.out.println(Arrays.deepToString(res.toArray()));
        Solution s = new Solution();
        System.out.println(s.minWindow("ADOBECODEBANC", "ABC"));
    }
}
