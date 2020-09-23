class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashMap<Integer, Integer>[] row = new HashMap[9];
        HashMap<Integer, Integer>[] col = new HashMap[9];
        HashMap<Integer, Integer>[] box = new HashMap[9];
        for (int i = 0; i < 9; i++) {
            row[i] = new HashMap<Integer, Integer>();
            col[i] = new HashMap<Integer, Integer>();
            box[i] = new HashMap<Integer, Integer>();
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                int boxNum = j / 3 + (i / 3) * 3;
                if (row[i].containsKey(cur)) return false;
                if (col[j].containsKey(cur)) return false;
                if (box[boxNum].containsKey(cur)) return false;

                row[i].put(cur, 1);
                col[j].put(cur, 1);
                box[boxNum].put(cur, 1);
            }
        }
        return true;
    }
}