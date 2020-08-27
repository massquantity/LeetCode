#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

double min(int a, int b) {
    return (double) (a < b ? a : b);
}

double findKthElem(int *nums1, int nums1Size, int *nums2, int nums2Size, int k) {
    int index1 = 0, index2 = 0;
    while (true) {
        if (index1 == nums1Size) return nums2[index2 + k - 1];
        if (index2 == nums2Size) return nums1[index1 + k - 1];
        if (k == 1) return min(nums1[index1], nums2[index2]);

        int half = k / 2;
        int newIndex1 = min(index1 + half, nums1Size) - 1;
        int newIndex2 = min(index2 + half, nums2Size) - 1;
        if (nums1[newIndex1] <= nums2[newIndex2]) {
            k -= (newIndex1 - index1 + 1);
            index1 = newIndex1 + 1;
        } else {
            k -= (newIndex2 - index2 + 1);
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size){
    int len = nums1Size + nums2Size;
    if (len % 2 == 1) {
        int mid = len / 2 + 1;
        return findKthElem(nums1, nums1Size, nums2, nums2Size, mid);
    } else {
        int mid1 = len / 2, mid2 = len / 2 + 1;
        double left = findKthElem(nums1, nums1Size, nums2, nums2Size, mid1);
        double right = findKthElem(nums1, nums1Size, nums2, nums2Size, mid2);
        return (left + right) / 2.;
    }
}


int main(void) {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    printf("%lf\n", findMedianSortedArrays(nums1, 2, nums2, 1));
}

