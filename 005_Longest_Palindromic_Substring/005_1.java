import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2) return s;
        boolean dp[][] = new boolean[len][len];
        for (int i = 0; i < len; ++i)
            dp[i][i] = true;

        int maxLen = 1, start = 0;
        for (int j = 1; j < len; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s.charAt(i) == s.charAt(j)) {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = false;
                }

                if (dp[i][j]) {
                    int curLen = j - i + 1;
                    if (curLen > maxLen) {
                        maxLen = curLen;
                        start = i;
                    }
                }
            }
        }
        return s.substring(start, start + maxLen);
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        String str = "babad";
        System.out.println(s.longestPalindrome(str));
    }
}