
class Solution {
    int res = 0;
    public int totalNQueens(int n) {
        char[][] c = new char[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(c[i], '.');
        backtrack(c, 0);
        return res;
    }

    private void backtrack(char[][] one, int row) {
        int n = one.length;
        if (row == n) {
            res++;
            return;
        }
            
        for (int col = 0; col < n; col++) {
            if (!isValid(one, row, col)) continue;
            one[row][col] = 'Q';
            backtrack(one, row + 1);
            one[row][col] = '.';
        }
    }

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
}
