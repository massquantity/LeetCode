int* constructArr(int* a, int aSize, int* returnSize){
    if (aSize == 0) {
        *returnSize = 0;
        return a;
    }

    int *res = (int *)malloc(sizeof(int) * aSize);
    for (int i = 0; i < aSize; i++) res[i] = 1;
    res[0] = 1;
    res[aSize - 1] = 1;
    int left = 1, right = 1;
    for (int i = 0; i < aSize; i++) {
        res[i] *= left;
        left *= a[i];

        res[aSize - i - 1] *= right;
        right *= a[aSize - i - 1]; 
    }
    *returnSize = aSize;
    return res;
}