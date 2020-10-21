bool canJump(int* nums, int numsSize){
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > m) return false;
        m = m > i + nums[i] ? m : i + nums[i];
    }
    return true;
}