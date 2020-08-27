#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int abs(x) {
    return x >= 0 ? x : -x;
}

int comp(const void *p1, const void *p2) {
    return *(const int *)p1 - *(const int *)p2;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), comp);
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int cur = nums[i] + nums[j] + nums[k];
            if (abs(cur - target) < abs(res - target)) res = cur;
            if (cur == target) return res;
            else if (cur < target) j++;
            else if (cur > target) k--;
        }
    }
    return res;
}

int main(void) {
    int nums[] = {-1, 2, 1, -4};
    printf("%d\n", threeSumClosest(nums, 4, 1));
}

