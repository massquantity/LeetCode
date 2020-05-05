import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int[] res = new int[n+1];
        res[1] = 1;
        res[2] = 2;
        res[3] = 3;
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j)
                res[i] = Math.max(res[i], res[j] * res[i - j]);
        }
        return res[n];
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.cuttingRope(10));
    }
}