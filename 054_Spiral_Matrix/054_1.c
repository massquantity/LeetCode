int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int l = 0, r = matrixColSize[0] - 1, t = 0, b = matrixSize - 1;
    int k = 0;
    *returnSize = matrixSize * matrixColSize[0];
    int* res = (int *)malloc(sizeof(int) * (*returnSize));
    while (true) {
        for (int i = l; i <= r; i++) res[k++] = matrix[t][i];
        if (++t > b) break;
        for (int i = t; i <= b; i++) res[k++] = matrix[i][r];
        if (--r < l) break;
        for (int i = r; i >= l; i--) res[k++] = matrix[b][i];
        if (--b < t) break;
        for (int i = b; i >= t; i--) res[k++] = matrix[i][l];
        if (++l > r) break;
    }
    return res;
}