#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool findNumberIn2DArray(int **matrix, int matrixSize, int *matrixColSize, int target){
    if (matrixSize == 0 || *matrixColSize == 0) return false;
    int row = 0, col = *matrixColSize - 1;
    while (row < matrixSize && col >= 0) {
        if      (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target)  row++;
        else                                 col--;
    }
    return false;
}

int main(void) {
    int m[5][5] ={{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22},
                  {10,13,14,17,24}, {18,21,23,26,30}};
    size_t row = sizeof(m) / sizeof(m[0]);
    size_t col = sizeof(m[0]) / sizeof(int);
    int **matrix = (int **)malloc(sizeof(int *) * row * col);
    /*
    for (int i = 0; i < row; ++i) {
        matrix[i] = (int *)malloc(sizeof(int) * col);
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = m[i][j];
        }
    } */
    for (int i = 0; i < row; ++i)
        matrix[i] = m[i];
    printf("%d\n", findNumberIn2DArray(matrix, 5, &col, 5));
}