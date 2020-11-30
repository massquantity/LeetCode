#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

void dfs(int* nums, int numsSize, int* returnSize, int* returnColumnSizes,
         int **res, int *tmp, int index, int cur)
{
    if (index == numsSize) return;
    for (int i = index; i < numsSize; i++) {
        tmp[cur] = nums[i];
        int size = cur + 1;
        res[*returnSize] = (int *)malloc(sizeof(int) * size);
        memcpy(res[*returnSize], tmp, sizeof(int) * size);
        returnColumnSizes[*returnSize] = size;
        (*returnSize)++;
        dfs(nums, numsSize, returnSize, returnColumnSizes, res, tmp, i + 1, cur + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * 5000);
    res[0] = (int *)malloc(sizeof(int));
    *returnSize = 1;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 5000);
    *returnColumnSizes[0] = 0;
    int tmp[numsSize];
    dfs(nums, numsSize, returnSize, *returnColumnSizes, res, tmp, 0, 0);
    return res;
}


int main(void) {
    int nums[] = {1,2,3};
    int *returnSize = (int *)malloc(sizeof(int) * 100);
    int **returnColumnSizes = (int **)malloc(sizeof(int *) * 100);
    int **res = subsets(nums, 3, returnSize, returnColumnSizes);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}