inline int MAX(int a, int b) {
    return a > b ? a : b;
}

inline int robRange(int* nums, int start, int end) {
    int prev = 0, curr = 0;
    for (int i = end; i >= start; --i) {
        int tmp = curr;
        curr = MAX(prev + nums[i], curr);
        prev = tmp;
    }
    return curr;
}

int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    return MAX(robRange(nums, 0, numsSize - 2), 
               robRange(nums, 1, numsSize - 1));
}