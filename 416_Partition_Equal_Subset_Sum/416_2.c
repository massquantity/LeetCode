int comp(const void *p1, const void *p2) {
    return *(const int *)p1 - *(const int *)p2;
}

bool dfs(int sum, int index, int *nums, int n) {
    if (sum == 0) return true;
    if (sum < 0) return false;
    for (int i = index; i < n; i++) {
        if (dfs(sum - nums[i], i + 1, nums, n)) {
            return true;
        }
    }
    return false;
}

// 超时
bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) return false;
    qsort(nums, numsSize, sizeof(int), comp);
    return dfs(sum / 2, 0, nums, numsSize);
}
