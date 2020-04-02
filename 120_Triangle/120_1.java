import java.util.List;
import java.util.ArrayList;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int m = triangle.size();
        int n = triangle.get(m - 1).size();
        int[] dp = new int[n + 1];
        for (int i = m - 1; i >= 0; --i) {
            List<Integer> rows = triangle.get(i);
            for (int j = 0; j < rows.size(); ++j) {
                dp[j] = rows.get(j) + Math.min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
}

public class leetcode {
    public static void main(String[] args) {
        List<Integer> t1 = new ArrayList<>();
        List<Integer> t2 = new ArrayList<>();
        List<Integer> t3 = new ArrayList<>();
        List<Integer> t4 = new ArrayList<>();
        t1.add(2);
        t2.add(3);
        t2.add(4);
        t3.add(6);
        t3.add(5);
        t3.add(7);
        t4.add(4);
        t4.add(1);
        t4.add(8);
        t4.add(3);
        List<List<Integer>> t = new ArrayList<>();
        t.add(t1);
        t.add(t2);
        t.add(t3);
        t.add(t4);
        Solution s = new Solution();
        System.out.println(s.minimumTotal(t));
    }
}