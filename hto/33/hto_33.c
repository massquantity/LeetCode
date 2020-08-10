#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

bool recur(int *array, int i, int j) {
    if (i >= j) return true;
    int p = i;
    while (array[p] < array[j]) p++;
    int m = p;
    while (array[p] > array[j]) p++;
    return p == j && recur(array, i, m - 1) && recur(array, m, j - 1);
}

bool verifyPostorder(int* postorder, int postorderSize){
    return recur(postorder, 0, postorderSize - 1);
}


int main(void) {
    int a[] = {1, 3, 2, 6, 5};
    printf("%s", verifyPostorder(a, 5) ? "true" : "false");
}

