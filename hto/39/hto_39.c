int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    int halfLength = numsSize / 2;
    qsort(nums, numsSize, sizeof(int), comp);
    return nums[halfLength];
}

