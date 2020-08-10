#include <stdio.h>
#include <string.h>

int findRepeatNumber(int* nums, int numsSize) {
    int arr[numsSize];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < numsSize; ++i) {
        if (arr[nums[i]] > 0) return nums[i];
        else                  arr[nums[i]]++;
    }
    return -1;
}

int main(void) {
    int a[] = {2, 3, 1, 0, 2, 5, 3};
    printf("%d\n", findRepeatNumber(a, sizeof(a) / sizeof(int)));
}