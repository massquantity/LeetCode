#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int partition(int *arr, int lo, int hi) {
    int i = lo, j = hi + 1;
    int v = arr[lo];
    while (true) {
        while (++i <= hi && arr[i] < v);
        while (--j >= lo && arr[j] > v);
        if (i >= j) break;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    arr[lo] = arr[j];
    arr[j] = v;
    return j;
}

void quickSearch(int *arr, int lo, int hi, int k) {
    // select random element to paratition
    // int r = rand() % (hi - lo + 1) + lo; 
    // int tmp = arr[lo];
    // arr[lo] = arr[r];
    // arr[r] = tmp;

    int m = partition(arr, lo, hi);
    if (m == k) return;
    else if (m < k) quickSearch(arr, m + 1, hi, k);
    else if (m > k) quickSearch(arr, lo, m - 1, k);
}


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if (k == 0 || arrSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    if (arrSize <= k) {
        *returnSize = arrSize;
        return arr;
    }
    *returnSize = k;
    quickSearch(arr, 0, arrSize - 1, k);
    int *res = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = arr[i];
    }
    return res;
}

int main(void) {
    int arr[] = {0,0,2,3,2,1,1,2,0,4};
    int qq = 0;
    int *returnSize = &qq;
    int *res = getLeastNumbers(arr, 10, 8, returnSize);
    for (int i = 0; i < 8; i++) {
        printf("%d ", res[i]);
    }
}

