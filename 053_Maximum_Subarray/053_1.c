#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int maxSubArray(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    int res = nums[0], sum = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        sum = (sum > 0 ? sum : 0) + nums[i];  // sum = max(sum + nums[i], nums[i])
        res = res > sum ? res : sum;
    }
    return res;
}

int maxSubArray2(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int res = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i - 1] > 0) nums[i] += nums[i - 1];
        res = res > nums[i] ? res : nums[i];
    }
    return res;
}

int main(void) {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSubArray(a, 9));
}

