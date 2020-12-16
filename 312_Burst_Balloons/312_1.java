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
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n + 2][n + 2];
        int[] points = new int[n + 2];
        points[0] = points[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            points[i] = nums[i - 1];
        }

        for (int i = n; i >= 0; i--) {
            for (int j = i + 1; j < n + 2; j++) {
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = Math.max(
                        dp[i][j], 
                        dp[i][k] + dp[k][j] + points[i] * points[j] * points[k]
                    );
                }
            }
        }
        return dp[0][n + 1];
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {3,1,5,8};
        System.out.println(s.maxCoins(nums));
    }
}
