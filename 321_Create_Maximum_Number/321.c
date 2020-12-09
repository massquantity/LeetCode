#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int *find_seq(int *nums, int numsSize, int k) {
    int remove_count = numsSize - k;
    int *stack = (int *)malloc(sizeof(int) * k);
    int top = -1;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        while (top >= 0 && remove_count > 0 && n > stack[top]) {
            top--;
            remove_count--;
        }
        if (top < k - 1) {
            stack[++top] = n;
        } else {
            remove_count--;
        }
    }
    return stack;
}

int *merge(int *seq1, int size1, int *seq2, int size2) {
    int compare(int *seq1, int index1, int size1, int *seq2, int index2, int size2);
    if (size1 == 0) return seq2;
    if (size2 == 0) return seq1;

    int len = size1 + size2;
    int *merged = (int *)malloc(sizeof(int) * len);
    int index1 = 0, index2 = 0;
    for (int i = 0; i < len; i++) {
        if (compare(seq1, index1, size1, seq2, index2, size2) > 0) {
            merged[i] = seq1[index1++];
        } else {
            merged[i] = seq2[index2++];
        }
    }
    return merged;
}

int compare(int *seq1, int index1, int size1, int *seq2, int index2, int size2) {
    while (index1 < size1 && index2 < size2) {
        int diff = seq1[index1] - seq2[index2];
        if (diff != 0) return diff;
        index1++;
        index2++;
    }
    return (size1 - index1) - (size2 - index2);
}

void swap(int** a, int** b) {
    int* tmp = *a;
    *a = *b, *b = tmp;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size,
               int k, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * k);
    memset(res, 0, sizeof(int) * k);
    *returnSize = k;
    for (int i = 0; i <= k; i++) {
        if (i > nums1Size || k-i > nums2Size) continue;
        int *seq1 = find_seq(nums1, nums1Size, i);
        int *seq2 = find_seq(nums2, nums2Size, k-i);
        int *merged = merge(seq1, i, seq2, k-i);
        if (compare(merged, 0, k, res, 0, k) > 0) {
            // memcpy(res, merged, sizeof(int) * k);
            swap(&res, &merged);
        }
    }
    return res;
}

int main(void) {
    int nums1[] = {3,4,6,5};
    int nums2[] = {9,1,2,5,8,3};
    int returnSize = 1;
    int *res = maxNumber(nums1, 4, nums2, 6, 5, &returnSize);
    for (int i = 0; i < 5; i++) {
        printf("%d ", res[i]);
    }
}

