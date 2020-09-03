int removeElement(int* nums, int numsSize, int val){
    if (numsSize == 0) return 0;
    int i = 0;
    int j = numsSize;
    while (i < j) {
        if (nums[i] == val) {
            nums[i] = nums[j - 1];
            j--;
        } else {
            i++;
        }
    }
    return i;
}