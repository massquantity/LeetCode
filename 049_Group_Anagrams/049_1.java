import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List<String>> m = new HashMap<>();
        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = String.valueOf(ca);
            if (!m.containsKey(key)) m.put(key, new ArrayList());
            m.get(key).add(s);
        }
        return new ArrayList(m.values());
    }
}

public class leetcode {
    public static void main(String[] args) {
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        Solution so = new Solution();
        List<List<String>> res = so.groupAnagrams(strs);
        System.out.println(Arrays.deepToString(res.toArray()));
    }
}