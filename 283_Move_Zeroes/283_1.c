void moveZeroes(int* nums, int numsSize){
    int i = 0, j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    while (j < numsSize) {
        nums[j++] = 0;
    }
}
