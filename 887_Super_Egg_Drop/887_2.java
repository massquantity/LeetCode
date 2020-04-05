import java.util.Arrays;
import java.util.Comparator;
import java.util.*;

class Solution {
    Map<Integer, Integer> memo = new HashMap<>();
    public int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    private int dp(int K, int N) {
        if (K == 1) return N;
        if (N == 0) return 0;
        if (!memo.containsKey(N * 100 + K)) {
            int lo = 1, hi = N;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                int broken = dp(K - 1, mid - 1);
                int n_broken = dp(K, N - mid);
                if (broken < n_broken)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            int res = 1 + Math.min(Math.max(dp(K-1, lo-1), dp(K, N-lo)),
                                   Math.max(dp(K-1, hi-1), dp(K, N-hi)));
            memo.put(N * 100 + K, res);
        }
        return memo.get(N * 100 + K);
    }
}  

public class leetcode {
    public static void main(String[] args) {
        int K = 100, N = 8192;
        Solution s = new Solution();
        System.out.println(s.superEggDrop(K, N));
    }
}