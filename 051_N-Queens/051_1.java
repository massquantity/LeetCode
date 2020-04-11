import java.util.Arrays;
import java.util.Comparator;
import java.util.*;

class Solution {
    List<List<String>> res = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        char[][] c = new char[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(c[i], '.');
    //    List<char[]> one = new ArrayList<>();
    //    for (int i = 0; i < n; ++i)
    //        one.add(c);
        backtrack(c, 0);
        return res;
    }

    private void backtrack(char[][] one, int row) {
        int n = one.length;
        if (row == n) {
            addResult(one);
            return;
        }
            
        for (int col = 0; col < n; col++) {
            if (!isValid(one, row, col)) continue;
            one[row][col] = 'Q';
            backtrack(one, row + 1);
            one[row][col] = '.';
        }
    }
/*
    private boolean isValid(char[][] one, int row, int col) {
        int n = one.length;
        for (int i = 0; i < row; ++i) {
            if (one[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (one[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (one[i][j] == 'Q') return false;
        }
        return true;
    }
*/
    private boolean isValid(char[][] one, int row, int col) {
        int n = one.length;
        int leftUp = col - 1, rightUp = col + 1;
        for (int i = row - 1; i >= 0; --i) {
            if (one[i][col] == 'Q') return false;
            if (leftUp >= 0) 
                if (one[i][leftUp] == 'Q') return false;
            if (rightUp < n)
                if (one[i][rightUp] == 'Q') return false;
            leftUp--;
            rightUp++;
        }
        return true;
    }

    private void addResult(char[][] one) {
        int n = one.length;
        List<String> s = new ArrayList<>();
        for (int i = 0; i < n; ++i)
            s.add(new String(one[i]));
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