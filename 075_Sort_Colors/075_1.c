void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void sortColors(int* nums, int numsSize){
    if (numsSize == 0) return nums;
    int i = 0, left = 0, right = numsSize;
    while (i < right) {
        if (nums[i] == 0) {
            swap(nums, i, left);
            left++;
            i++;
        } else if (nums[i] == 2) {
            --right;
            swap(nums, i, right);
        } else {
            i++;
        }
    }
    return nums;
}