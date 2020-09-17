int trap(int* height, int heightSize){
    if (heightSize == 0 || heightSize == 1) return 0;
    int res = 0;
    int i = 0, j = heightSize - 1;
    int leftMax = height[i], rightMax = height[j];
    while (i < j) {
        if (height[i] <= height[j]) {
            i++;
            if (height[i] < leftMax) {
                res += (leftMax - height[i]);
            } else {
                leftMax = height[i];
            }
        } else {
            j--;
            if (height[j] < rightMax) {
                res += (rightMax - height[j]);
            } else {
                rightMax = height[j];
            }
        }
    }
    return res;
}