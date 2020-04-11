import java.util.Arrays;
import java.util.Comparator;
import java.util.*;

class Solution {
    List<List<String>> res = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        int[] c = new int[n];
        Arrays.fill(c, -1);
        backtrack(c, 0);
        return res;
    }

    private void backtrack(int[] one, int row) {
        int n = one.length;
        if (row == n) {
            addResult(one);
            return;
        }
            
        for (int col = 0; col < n; col++) {
            if (!isValid(one, row, col)) continue;
            one[row] = col;
            backtrack(one, row + 1);
            one[row] = -1;
        }
    }

    private boolean isValid(int[] one, int row, int col) {
        int n = one.length;
        int leftUp = col - 1, rightUp = col + 1;
        for (int i = row - 1; i >= 0; --i) {
            if (one[i] == col) return false;
            if (leftUp >= 0) 
                if (one[i] == leftUp) return false;
            if (rightUp < n)
                if (one[i] == rightUp) return false;
            leftUp--;
            rightUp++;
        }
        return true;
    }

    private void addResult(int[] one) {
        int n = one.length;
        List<String> s = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; ++j) {
                if (one[i] == j)
                    sb.append("Q");
                else
                    sb.append(".");
            }
            s.add(sb.toString());
        }
        System.out.println(s);
        res.add(s);
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        List<List<String>> res = s.solveNQueens(4);  
    }
}