#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *res = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    int *queue = (int *)malloc(sizeof(int) * 100);
    int left = 0, right = 0, j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (right > left && i - queue[left] >= k) left++;
        while (right > left && nums[queue[right-1]] < nums[i]) right--;
        queue[right++] = i;
        if (i >= k - 1) res[j++] = nums[queue[left]];
    }
    *returnSize = j;
    return res;
}

int main(void) {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int yy = 0;
    int *res = maxSlidingWindow(nums, 8, 3, &yy);
    for (int i = 0; i < 6; i++) {
        printf("%d ", res[i]);
    }
}

