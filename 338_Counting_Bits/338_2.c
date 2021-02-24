int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int n = *returnSize;
    int *res = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }
    for (int i = 1; i <= num; i++) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}
