bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0 || *matrixColSize == 0 || target < matrix[0][0]) return false;
    int m = matrixSize, n = *matrixColSize;
    int row = 0;
    while (target > matrix[row][n - 1]) {
        row++;
        if (row == matrixSize) return false;
    }
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (target < matrix[row][mid])
            hi = mid;
        else if (target > matrix[row][mid])
            lo = mid + 1;
        else
            return true;
    }
    return false;
}