#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

void dfs(int *nums, int numsSize, int k, int **res, int *tmp, int *returnSize,
         int *returnColumnSizes, int index, int cur)
{
    if (index == k) {
        res[*returnSize] = (int *)malloc(sizeof(int) * k);
        memcpy(res[*returnSize], tmp, sizeof(int) * k);
        returnColumnSizes[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (int i = cur + 1; i < numsSize; i++) {
        tmp[index] = nums[i];
        dfs(nums, numsSize, k, res, tmp, returnSize, returnColumnSizes,
            index + 1, i);
    }
}

int** combine(int *nums, int numsSize, int k, int **res, int *tmp,
              int* returnSize, int** returnColumnSizes)
{
    dfs(nums, numsSize, k, res, tmp, returnSize, *returnColumnSizes, 0, -1);
    return res;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **res = (int **)malloc(sizeof(int *) * 5000);
    int tmp[numsSize];
    *returnSize = 1;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 5000);
    *returnColumnSizes[0] = 0;
    res[0] = (int *)malloc(sizeof(int));
    for (int i = 1; i <= numsSize; i++) {
        combine(nums, numsSize, i, res, tmp, returnSize, returnColumnSizes);
    }
    return res;
}

int main(void) {
    int nums[] = {1,2,3};
    int *returnSize = (int *)malloc(sizeof(int) * 1000);
    int **returnColumnSizes = (int **)malloc(sizeof(int *) * 1000);
    int **res = subsets(nums, 3, returnSize, returnColumnSizes);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
