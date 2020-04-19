bool search(int *nums, int numsSize, int target){
    if (numsSize == 0) return false;
    if (numsSize == 1) return target == nums[0] ? true : false;
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return true;
        if (nums[lo] == nums[mid]) lo++;
        else if (nums[lo] < nums[mid]) {
            if (target >= nums[lo] && target < nums[mid])
                hi = mid;
            else
                lo = mid + 1;
        } 
        else {
            if (target > nums[mid] && target < nums[lo])
                lo = mid + 1;
            else
                hi = mid;
        }
    }
    return false;
}