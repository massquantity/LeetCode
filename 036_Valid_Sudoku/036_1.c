bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9][10] = {0};
    int col[9][10] = {0};
    int box[9][10] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            int cur = board[i][j] - '0';
            int boxNum = j / 3 + (i / 3) * 3;
            if (row[i][cur]) return false;
            if (col[j][cur]) return false;
            if (box[boxNum][cur]) return false;

            row[i][cur] = 1;
            col[j][cur] = 1;
            box[boxNum][cur] = 1;
        }
    }
    return true;
}