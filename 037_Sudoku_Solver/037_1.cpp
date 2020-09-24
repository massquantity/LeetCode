class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(box, false, sizeof(box));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int k = (i / 3) * 3 + j / 3;
                row[i][num] = col[j][num] = box[k][num] = true;
            }
        }
        backtrack(board, 0);
    }

    bool backtrack(vector<vector<char>>& board, int n) {
        if (n == 81) return true;
        int i = n / 9, j = n % 9;
        if (board[i][j] != '.') return backtrack(board, n + 1);
        
        int k = (i / 3) * 3 + j / 3;
        for (int num = 0; num < 9; num++) {
            if (row[i][num] || col[j][num] || box[k][num]) continue;
            board[i][j] = (char)(num + '1');
            row[i][num] = col[j][num] = box[k][num] = true;
            if (backtrack(board, n + 1)) return true;
            row[i][num] = col[j][num] = box[k][num] = false;
        }
        board[i][j] = '.';
        return false;
    }

private:
    bool row[9][9];
    bool col[9][9];
    bool box[9][9];
};