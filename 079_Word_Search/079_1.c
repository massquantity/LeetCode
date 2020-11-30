#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

bool backtrack(char **board, int index, int i, int j, int row, int col,
               char *word, bool visited[row][col])
{
    if (index == strlen(word)) return true;
    if (i < 0 || i >= row || j < 0 || j >= col
        || visited[i][j] || board[i][j] != word[index]) return false;
    visited[i][j] = true;
    bool res = backtrack(board, index + 1, i - 1, j, row, col, word, visited)
            || backtrack(board, index + 1, i + 1, j, row, col, word, visited)
            || backtrack(board, index + 1, i, j - 1, row, col, word, visited)
            || backtrack(board, index + 1, i, j + 1, row, col, word, visited);
    visited[i][j] = false;
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    bool visited[boardSize][*boardColSize];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (backtrack(board, 0, i, j, boardSize, *boardColSize, word, visited))
                return true;
        }
    }
    return false;
}


int main(void) {
    char **board = (char **)malloc(sizeof(int *) * 3);
    char cc[3][4] = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    for (int i = 0; i < 3; i++) {
        board[i] = cc[i];
    }
    int boardColSize = 4;
    printf("%s\n", exist(board, 3, &boardColSize, "ABCCED") ? "true" : "false");
}
