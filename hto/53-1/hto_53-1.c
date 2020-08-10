int missingNumber(int* nums, int numsSize){
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (nums[mid] == mid) 
            lo = mid + 1;
        else if (nums[mid] > mid)
            hi = mid;
    }
    return lo;
}