#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int jump(int* nums, int numsSize){
    int end = 0, maxPos = 0, steps = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        maxPos = maxPos > i + nums[i] ? maxPos : i + nums[i];
        if (i == end) {
            end = maxPos;
            steps++;
        }
    }
    return steps;
}


int main(void) {
    int nums[] = {2,3,1,1,4};
    printf("%d\n", jump(nums, 5));
}

