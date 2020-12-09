int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0 || *matrixColSize == 0) return 0;
    int res = 0;
    int m = matrixSize, n = *matrixColSize;
    int height[n + 2];
    memset(height, 0, sizeof(height));
    for (int i = 0; i < m; i++) {
        int stack[n + 2];
        memset(stack, 0, sizeof(stack));
        int top = 0;
        for (int j = 1; j < n + 2; j++) {
            if (j-1 < n && matrix[i][j-1] == '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
            while (height[stack[top]] > height[j]) {
                int curHeight = height[stack[top]];
                top--;
                int curWidth = j - stack[top] - 1;
                res = fmax(res, curHeight * curWidth);
            }
            stack[++top] = j;
        }
    }
    return res;
}
