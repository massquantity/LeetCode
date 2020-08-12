int binarySearch(int *nums, int lo, int hi, int target) {
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (nums[mid] == target) 
            return 1;
        else if (nums[mid] < target)
            lo = mid + 1;
        else if (nums[mid] > target)
            hi = mid;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++) {
        int other = target - nums[i];
        if (binarySearch(nums, i + 1, numsSize, other) == 1) {
            res[0] = nums[i];
            res[1] = other;
            break;
        }
    }
    return res;
}