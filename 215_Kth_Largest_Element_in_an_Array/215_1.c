#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void maxHeapify(int *nums, int k, int n) {
    while (2*k + 1 < n) {
        int j = 2*k + 1;
        if (j < n - 1 && nums[j] < nums[j+1]) j++;
        if (nums[k] > nums[j]) break;
        swap(nums, j, k);
        k = j;
    }
}

void buildHeap(int *nums, int n) {
    for (int i = n / 2; i >= 0; i--)
        maxHeapify(nums, i, n);
}

int findKthLargest(int* nums, int numsSize, int k){
    int n = numsSize;
    buildHeap(nums, numsSize);
    while (n > numsSize - k + 1) {
        swap(nums, 0, n - 1);
        n--;
        maxHeapify(nums, 0, n);
    }
    return nums[0];
}


int main(void) {
    int nums[] = {77,1,6,6,3,0,12,45,0,0};
    printf("%d", findKthLargest(nums, 8, 2));
}

