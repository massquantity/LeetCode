#include <stdio.h>
#include <math.h>

// compile with "-lm" option,  gcc xxx.c -lm
int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1, area = 0;
    while (left < right) {
        area = fmax(area, fmin(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) left++;
        else                              right--;
    }
    return area;
}

int main(void) {
    int height[] = {1,8,6,2,5,4,8,3,7};
    size_t heightSize = sizeof(height) / sizeof(int);
    printf("%d\n", maxArea(height, heightSize));
}