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
    List<String> res = new LinkedList<>();
    char[] c;
    public String[] permutation(String s) {
        c = s.toCharArray();
        dfs(0);
        return res.toArray(new String[res.size()]);
    }

    void dfs(int pos) {
        if (pos == c.length - 1) {
            res.add(String.valueOf(c));
            return;
        }
        Set<Character> set = new HashSet<>();
        for (int i = pos; i < c.length; i++) {
            if (set.contains(c[i])) continue;
            set.add(c[i]);
            swap(pos, i);
            dfs(pos + 1);
            swap(pos, i);
        }
    }

    void swap(int i, int j) {
        char tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        String str = "abc";
        for (String ss : s.permutation(str)) {
            System.out.println(ss);
        }
    }
}


