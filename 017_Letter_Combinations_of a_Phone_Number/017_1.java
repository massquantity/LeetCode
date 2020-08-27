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
    private String[] map = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    private StringBuilder sb = new StringBuilder();
    public List<String> res = new ArrayList<>();;

    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0) return res;
        backtrack(digits, 0);
        return res;
    }

    private void backtrack(String digits, int index) {
        if (index == digits.length()) res.add(sb.toString());
        else {
            int d = digits.charAt(index) - '2';
            String letters = map[d];
            for (char ch : letters.toCharArray()) {
                sb.append(ch);
                backtrack(digits, index + 1);
                sb.deleteCharAt(index);
            }
        }
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.letterCombinations("23"));
    }
}


