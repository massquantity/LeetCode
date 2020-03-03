#include <stdio.h>
#include <stdlib.h>


int comp(const void *p1, const void *p2) {
    return *(const int *)p1 - *(const int *)p2;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    *returnColumnSizes = (int *)malloc(sizeof(int) * (numsSize + 1) * 6);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 2; ++i) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int j = i + 1;
            int k = numsSize - 1;
            while (j < k) {
                int allSum = nums[i] + nums[j] + nums[k];
                if (allSum == 0) {
                    res[*returnSize] = (int *)malloc(sizeof(int) * 3);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[k];
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;

                    while (j < k && nums[j] == nums[++j]);
                    while (j < k && nums[k] == nums[--k]);
                } else if (allSum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
    }
    return res;
}


int main() {
	int a[] = {-1, 0, 1, 2, -1, -4};
	int r = 1;
	int *r1 = &r;
	int **r2 = &r1;
	int **res = threeSum(a, sizeof(a) / sizeof(int), r1, r2);
	int i = 0;
	while (i < 9) {
		if (i < 3 || i > 5)
		    printf("%d ", *(*res + i));  // (*res)[i]
		if (i == 2)
		    printf("\n");
		i++;
	}
}