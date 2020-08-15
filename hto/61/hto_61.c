int partition(int *nums, int lo, int hi) {
    int v = nums[lo];
    int i = lo, j = hi + 1;
    while (true) {
        while (++i < hi && nums[i] < v);
        while (--j > lo && nums[j] > v);
        if (i >= j) break;
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    nums[lo] = nums[j];
    nums[j] = v;
    return j;
}

void quickSort(int *nums, int lo, int hi) {
    if (lo >= hi) return;
    int p = partition(nums, lo, hi);
    quickSort(nums, lo, p - 1);
    quickSort(nums, p + 1, hi);
}

bool isStraight(int* nums, int numsSize){
    quickSort(nums, 0, numsSize - 1);
    int count_zero = 0, diff = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == 0) count_zero++;
        else {
            if (nums[i] == nums[i+1]) return false;
            else if (nums[i] + 1 != nums[i+1]) 
                diff += (nums[i+1] - nums[i] - 1);
        }
    }
    return count_zero >= diff;
}

