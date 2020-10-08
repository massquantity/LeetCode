#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int firstMissingPositive(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] - 1 < numsSize && nums[i] != nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) return i + 1;
    }
    return numsSize + 1;
}


int main(void) {
    int nums[] = {3, 4, -1, 1};
    printf("%d\n", firstMissingPositive(nums, 4));
}

