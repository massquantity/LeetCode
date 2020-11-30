#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

void dfs(int cur, int numSize, int n, int k, int **res, int *tmp,
         int *returnSize, int *returnColumnSizes)
{
    if (numSize == k) {
        res[*returnSize] = (int *)malloc(sizeof(int) * numSize);
        memcpy(res[*returnSize], tmp, sizeof(int) * numSize);
        returnColumnSizes[*returnSize] = numSize;
        (*returnSize)++;
        return;
    }

    for (int i = cur + 1; i <= n; i++) {
        tmp[numSize] = i;
        dfs(i, numSize + 1, n, k, res, tmp, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int **res = (int **)malloc(sizeof(int *) * 5000);
    int *tmp = (int *)malloc(sizeof(int) * k);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 5000);
    if (n == 0 || k == 0 || n < k) {
        *returnSize = 1;
        *returnColumnSizes[0] = 0;
        return res;
    }
    dfs(0, 0, n, k, res, tmp, returnSize, *returnColumnSizes);
    return res;
}


int main(void) {
    int *returnSize = (int *)malloc(sizeof(int) * 1000);
    int **returnColumnSizes = (int **)malloc(sizeof(int *) * 1000);
    int **res = combine(4, 2, returnSize, returnColumnSizes);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

