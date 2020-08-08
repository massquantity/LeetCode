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

struct Heap {
    int *arr;
    int size;
};

typedef struct {
   struct Heap *minHeap;
   struct Heap *maxHeap;
} MedianFinder;

void push(struct Heap *heap, int num, bool minCond) {
    int *arr = heap->arr;
    int k = heap->size;
    arr[k] = num;
    if (minCond) {
        while (k > 0 && arr[(k-1)/2] > arr[k]) {
            swap(arr, (k-1)/2, k);
            k = (k-1)/2;
        }
    } else {
        while (k > 0 && arr[(k-1)/2] < arr[k]) {
            swap(arr, (k-1)/2, k);
            k = (k-1)/2;
        }
    }
    heap->size++;
}

int pop(struct Heap *heap, bool minCond) {
    int *arr = heap->arr;
    int n = heap->size;
    int target = arr[0];
    swap(arr, 0, n-1);
    n--;
    int k = 0;
    if (minCond) {
        while (2*k + 1 < n) {
            int j = 2*k + 1;
            if (j < n-1 && arr[j] > arr[j+1]) j++;
            if (arr[k] < arr[j]) break;
            swap(arr, j, k);
            k = j;
        }
    } else {
        while (2*k + 1 < n) {
            int j = 2*k + 1;
            if (j < n-1 && arr[j] < arr[j+1]) j++;
            if (arr[k] > arr[j]) break;
            swap(arr, j, k);
            k = j;
        }
    }
    heap->size--;
    return target;
}

MedianFinder* medianFinderCreate() {
    MedianFinder *mm = (MedianFinder *)malloc(sizeof(MedianFinder));
    mm->minHeap = (struct Heap *)malloc(sizeof(struct Heap));
    mm->maxHeap = (struct Heap *)malloc(sizeof(struct Heap));
    mm->minHeap->arr = (int *)malloc(sizeof(int) * 10000);
    mm->maxHeap->arr = (int *)malloc(sizeof(int) * 10000);
    mm->minHeap->size = 0;
    mm->maxHeap->size = 0;
    return mm;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->minHeap->size != obj->maxHeap->size) {
        push(obj->minHeap, num, true);
        push(obj->maxHeap, pop(obj->minHeap, true), false);
    } else {
        push(obj->maxHeap, num, false);
        push(obj->minHeap, pop(obj->maxHeap, false), true);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    return (obj->minHeap->size == obj->maxHeap->size)
    ? (obj->minHeap->arr[0] + obj->maxHeap->arr[0]) / 2.0
    : obj->minHeap->arr[0];
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->minHeap->arr);
    free(obj->maxHeap->arr);
    free(obj->minHeap);
    free(obj->maxHeap);
    free(obj);
}


int main(void) {
    /* test heap
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));
    heap->arr = (int *)malloc(sizeof(int) * 100);
    heap->size = 0;
    push(heap, 1, false);
    push(heap, 4, false);
    push(heap, 9, false);
    push(heap, 3, false);
    push(heap, 6, false);
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
    while (heap->size) {
        printf("%d ", pop(heap, false));
    } */

    MedianFinder* obj = medianFinderCreate();
    medianFinderAddNum(obj, 1);
    medianFinderAddNum(obj, 2);
    printf("%lf\n", medianFinderFindMedian(obj));
    medianFinderAddNum(obj, 3);
    printf("%lf\n", medianFinderFindMedian(obj));
    medianFinderFree(obj);
}

