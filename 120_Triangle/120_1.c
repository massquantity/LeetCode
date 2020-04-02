#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    for (int i = triangleSize - 2; i >= 0; --i) {
        for (int j = 0; j < triangleColSize[i]; ++j) {
            triangle[i][j] += MIN(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

int main(void) {
    int **triangle = (int **)malloc(sizeof(int *) * 4);
    triangle[0] = (int *)malloc(sizeof(int));
    triangle[0][0] = 2;
    triangle[1] = (int *)malloc(sizeof(int) * 2);
    triangle[1][0] = 3;  triangle[1][1] = 4;
    triangle[2] = (int *)malloc(sizeof(int) * 3);
    triangle[2][0] = 6; triangle[2][1] = 5; triangle[2][2] = 7;
    triangle[3] = (int *)malloc(sizeof(int) * 4);
    triangle[3][0] = 4; triangle[3][1] = 1; triangle[3][2] = 8; triangle[3][3] = 3;
    int colSizes[4] = {1, 2, 3, 4};
    printf("%d\n", minimumTotal(triangle, 4, colSizes));
}

