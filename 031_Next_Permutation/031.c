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

void reverse(int *nums, int i, int j) {
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(int* nums, int numsSize){
    if (numsSize == 0) return;
    int j = numsSize - 2;
    while (j >= 0 && nums[j] >= nums[j + 1]) {
        j--;
    }
    if (j >= 0) {   // else j = -1
        int k = numsSize - 1;
        while (k >= j) {
            if (nums[k] > nums[j]) break;
            k--;
        }
        swap(nums, k, j);
    }
    reverse(nums, j + 1, numsSize - 1);
}

int main(void) {
    int nums[] = {3,2,1};
    nextPermutation(nums, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d ", nums[i]);
    }
}

