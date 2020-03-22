#include <stdio.h>

int maxArea(int* height, int heightSize){
    int area = 0;
    int area2;
    for (int i = 0; i < heightSize; ++i) {
        for (int j = 1; j < heightSize; ++j) {
            area2 = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
            if (area < area2) area = area2;
        }
    }
    return area;
}

int main(void) {
    int height[] = {1,8,6,2,5,4,8,3,7};
    size_t heightSize = sizeof(height) / sizeof(int);
    printf("%d\n", maxArea(height, heightSize));
}