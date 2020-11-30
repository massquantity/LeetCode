int numSize = 0;

void dfs(int cur, int n, int k, int **res, int *tmp,
         int *returnSize, int *returnColumnSizes)
{
    if (numSize == k) {
        res[*returnSize] = (int *)malloc(sizeof(int) * numSize);
        memcpy(res[*returnSize], tmp, sizeof(int) * numSize);
        returnColumnSizes[*returnSize] = numSize;
        (*returnSize)++;
        return;
    }

    for (int i = cur + 1; i <= n; i++) {
        tmp[numSize++] = i;
        dfs(i, n, k, res, tmp, returnSize, returnColumnSizes);
        numSize--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int **res = (int **)malloc(sizeof(int *) * 5000);
    int *tmp = (int *)malloc(sizeof(int) * k);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 5000);
    if (n == 0 || k == 0 || n < k) {
        *returnSize = 1;
        *returnColumnSizes[0] = 0;
        return res;
    }
    dfs(0, n, k, res, tmp, returnSize, *returnColumnSizes);
    return res;
}
