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
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (s.isEmpty() || words.length == 0) return  res;
        int oneLen = words[0].length();
        int allLen = words.length * oneLen;
        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            int num = wordMap.getOrDefault(word, 0);
            wordMap.put(word, num + 1);
        }

        for (int i = 0; i < oneLen; i++) {
            int left = i, right = i, count = 0;
            Map<String, Integer> tmpMap = new HashMap<>();
            while (right + oneLen <= s.length()) {
                String w = s.substring(right, right + oneLen);
                right += oneLen;
                if (!wordMap.containsKey(w)) {
                    left = right;
                    count = 0;
                    tmpMap.clear();
                } else {
                    int num = tmpMap.getOrDefault(w, 0);
                    tmpMap.put(w, num + 1);
                    count++;
                    while (tmpMap.get(w) > wordMap.get(w)) {
                        String tmpWord = s.substring(left, left + oneLen);
                        tmpMap.put(tmpWord, tmpMap.getOrDefault(tmpWord, 0) - 1);
                        count--;
                        left += oneLen;
                    }
                }
                if (count == words.length) res.add(left);
            }
        }
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        String s = "barfoothefoobarman";
        String[] words = {"foo","bar"};
        Solution so = new Solution();
        System.out.println(so.findSubstring(s, words));
    }
}

