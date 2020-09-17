int trap(int* height, int heightSize){
    if (heightSize == 0 || heightSize == 1) return 0;
    int res = 0;
    int *leftMax = (int *)calloc(heightSize, sizeof(int));
    int *rightMax = (int *)calloc(heightSize, sizeof(int)); 
    leftMax[0] = height[0];
    rightMax[heightSize - 1] = height[heightSize - 1];
    for (int i = 1; i < heightSize; i++) {
        leftMax[i] = fmax(height[i], leftMax[i - 1]);
    }
    for (int i = heightSize - 2; i >= 0; i--) {
        rightMax[i] = fmax(height[i], rightMax[i + 1]);
    }

    for (int i = 1; i < heightSize - 1; i++) {
        res += (fmin(leftMax[i], rightMax[i]) - height[i]);
    }
    return res;
}