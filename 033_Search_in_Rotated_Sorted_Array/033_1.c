int search(int *nums, int numsSize, int target){
    if (numsSize == 0) return -1;
    if (numsSize == 1) return target == nums[0] ? 0 : -1;
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[lo] < nums[mid]) {
            if (target >= nums[lo] && target < nums[mid])
                hi = mid;
            else
                lo = mid + 1;
        } else {
            if (target > nums[mid] && target < nums[lo])
                lo = mid + 1;
            else
                hi = mid;
        }
    }
    return -1;
}

int main(void) {
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(nums, 7, 0));
    int n[] = {4, 5, 0, 1, 2};
    printf("%d\n", search(n, 5, 0));
}