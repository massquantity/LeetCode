#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

bool backtrack(char **board, bool row[9][9], bool col[9][9],
               bool box[3][3][9], int r, int c) {
    if (c == 9) {
        c = 0;
        r++;
        if (r == 9) return true;
    }

    if (board[r][c] == '.') {
        for (int i = 1; i <= 9; i++) {
            if (!row[r][i-1] && !col[c][i-1] && !box[r/3][c/3][i-1]) {
                row[r][i-1] = col[c][i-1] = box[r/3][c/3][i-1] = true;
                board[r][c] = (char)(i + '0');
                if (backtrack(board, row, col, box, r, c + 1))
                    return true;
                board[r][c] = '.';
                row[r][i-1] = col[c][i-1] = box[r/3][c/3][i-1] = false;
            }
        }
    } else {
        return backtrack(board, row, col, box, r, c + 1);
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    bool row[9][9];
    bool col[9][9];
    bool box[3][3][9];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(box, false, sizeof(box));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            int num = board[i][j] - '0';
            if (num >= 1 && num <= 9) {
                row[i][num-1] = true;
                col[j][num-1] = true;
                box[i/3][j/3][num-1] = true;
            }
        }
    }
    backtrack(board, row, col, box, 0, 0);
}


int main(void) {
    char board[9][9] = {{'5','3','.','.','7','.','.','.','.'},
                        {'6','.','.','1','9','5','.','.','.'},
                        {'.','9','8','.','.','.','.','6','.'},
                        {'8','.','.','.','6','.','.','.','3'},
                        {'4','.','.','8','.','3','.','.','1'},
                        {'7','.','.','.','2','.','.','.','6'},
                        {'.','6','.','.','.','.','2','8','.'},
                        {'.','.','.','4','1','9','.','.','5'},
                        {'.','.','.','.','8','.','.','7','9'}};

    int boardColSize = 9;
    solveSudoku(board, 9, &boardColSize);
}

