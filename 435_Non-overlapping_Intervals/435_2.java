import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) return 0;
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });
        int[] dp = new int[intervals.length];
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < intervals.length; ++i) {
            int max = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (intervals[j][1] <= intervals[i][0])
                    max = Math.max(dp[j], max);
            }
            dp[i] = max + 1;
            ans = Math.max(dp[i], ans);
        }
        return intervals.length - ans;
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[][] a = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
        Solution s = new Solution();
        System.out.println(s.eraseOverlapIntervals(a));
    }
}