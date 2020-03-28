class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String first = strs[0];
        for (int i = 1; i < strs.length; ++i) {
            // while (strs[i].indexOf(first) != 0)
            while (!strs[i].startsWith(first)) {
                first = first.substring(0, first.length() - 1);
                if (first.isEmpty()) return "";
            }
        }
        return first;
    }
}

public class leetcode {
    public static void main(String[] args) {
        String[] strs = {"flower", "flow", "flight"};
        Solution s = new Solution();
        System.out.println(s.longestCommonPrefix(strs));
    }
}