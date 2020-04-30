import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int movingCount(int m, int n, int k) {
        if (k == 0) return 1;
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        int res = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || digitSum(i) + digitSum(j) > k) continue;
                if (i - 1 >= 0) visited[i][j] |= visited[i - 1][j];
                if (j - 1 >= 0) visited[i][j] |= visited[i][j - 1];
                res += (visited[i][j] ? 1 : 0);
            }
        }
        return res;
    }

    private int digitSum(int x) {
        int res = 0;
        while (x != 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.movingCount(2, 3, 1));
    }
}