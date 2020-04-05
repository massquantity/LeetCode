import java.util.Arrays;
import java.util.Comparator;
import java.util.*;

class Solution {
    private Integer[][] memo;
    public int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    private int dp(int K, int N) {
        if (K == 1) return N;
        if (N == 0) return 0;
    //    List<Integer> key = Arrays.asList(K, N);
        if (memo == null) memo = new Integer[K + 1][N + 1];
        if (memo[K][N] != null) return memo[K][N];

        int res = Integer.MAX_VALUE;
    //    for (int i = 1; i <= N; ++i)   超时
    //        res = Math.min(res, Math.max(dp(K - 1, i - 1), dp(K, N - i)) + 1);
        
        int lo = 1, hi = N;
        while (lo <= hi) {    // 寻找最优的 i
            int mid = lo + (hi - lo) / 2;
            int broken = dp(K - 1, mid - 1);
            int not_broken = dp(K, N - mid);
            if (broken > not_broken) {
                hi = mid - 1;
                res = Math.min(res, broken + 1);
            } else {
                lo = mid + 1;
                res = Math.min(res, not_broken + 1);
            }
        }
        memo[K][N] = res;
        return res;
    }
}  

public class leetcode {
    public static void main(String[] args) {
        int K = 100, N = 8192;
        Solution s = new Solution();
        System.out.println(s.superEggDrop(K, N));
    }
}