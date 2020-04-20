int searchInsert(int* nums, int numsSize, int target){
    if (numsSize == 0) return 0;
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid])
            hi = mid;
        else if (target > nums[mid])
            lo = mid + 1;
    }
    return lo;
}