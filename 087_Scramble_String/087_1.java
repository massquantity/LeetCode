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
import java.util.Random;

class Solution {
    public boolean isScramble(String s1, String s2) {
        char[] chs1 = s1.toCharArray();
        char[] chs2 = s2.toCharArray();
        int m = chs1.length;
        int n = chs2.length;
        if (m != n) return false;
        boolean[][][] dp = new boolean[n][n][n+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (chs1[i] == chs2[j]);
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                for (int j = 0; j <= n-len; j++) {
                    for (int k = 1; k <= len-1; k++) {
                        if (dp[i][j][k] && dp[i+k][j+k][len-k]) {
                            dp[i][j][len] = true;
                            break;
                        }

                        if (dp[i][j+len-k][k] && dp[i+k][j][len-k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
}

public class leetcode {
    public static void main(String[] args) {
        System.out.println(new Solution().isScramble("great", "rgeat"));
    }
}
