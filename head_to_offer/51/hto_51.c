#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int merge(int *nums, int lo, int mid, int hi, int *aux) {
    for (int k = lo; k < hi; k++) {
        aux[k] = nums[k];
    }
    int count = 0;
    int i = lo, j = mid;
    for (int k = lo; k < hi; k++) {
        if (i >= mid) {
            nums[k] = aux[j++];
        }
        else if (j >= hi) {
            nums[k] = aux[i++];
        }
        else if (aux[i] <= aux[j]) {
            nums[k] = aux[i++];
        }
        else {
            nums[k] = aux[j++];
            count += (mid - i);
        }
    }
    return count;
}

int mergeCount(int *nums, int lo, int hi, int *aux) {
    if (lo + 1 >= hi) return 0;
    int mid = lo + (hi - lo) / 2;
    int leftPairs = mergeCount(nums, lo, mid, aux);
    int rightPairs = mergeCount(nums, mid, hi, aux);
    if (nums[mid - 1] <= nums[mid]) {
        return leftPairs + rightPairs;
    }
    int crossPairs = merge(nums, lo, mid, hi, aux);
    return leftPairs + rightPairs + crossPairs;
}

int reversePairs(int* nums, int numsSize){
    if (numsSize < 2) return 0;
    int *aux = (int *)malloc(sizeof(int) * numsSize);
    return mergeCount(nums, 0, numsSize, aux);
}


int main(void) {
    int arr[] = {7,5,6,4};
    printf("%d\n", reversePairs(arr, 4));
}

