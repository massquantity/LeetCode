#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int comp(const void *p1, const void *p2) {
    return *(const int *)p1 - *(const int *)p2;
}

void dfs(int *nums, int numsSize, int *returnSize, int *returnColumnSizes,
         int **res, int *tmp, bool *used, int index) {
    if (index == numsSize) {
        res[*returnSize] = (int *)malloc(sizeof(int) * numsSize);
        memcpy(res[*returnSize], tmp, sizeof(int) * numsSize);
        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

        tmp[index] = nums[i];
        used[i] = true;
        dfs(nums, numsSize, returnSize, returnColumnSizes, res, tmp, used, index + 1);
        used[i] = false;
    }
}

int** permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * 1000);
    int *tmp = (int *)malloc(sizeof(int) * 1000);
    bool *used = (bool *)malloc(sizeof(bool) * numsSize);
    memset(used, false, numsSize);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    qsort(nums, numsSize, sizeof(int), comp);
    dfs(nums, numsSize, returnSize, *returnColumnSizes, res, tmp, used, 0);
    return res;
}


int main(void) {
    int nums[] = {1,1,2};
    int *returnSize = (int *)malloc(sizeof(int) * 100);
    int **returnColumnsSizes = (int **)malloc(sizeof(int *) * 100);
    int **res = permuteUnique(nums, 3, returnSize, returnColumnsSizes);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

