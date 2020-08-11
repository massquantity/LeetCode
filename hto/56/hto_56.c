int* singleNumbers(int* nums, int numsSize, int* returnSize){
    int ret = 0;
    for (int i = 0; i < numsSize; i++) 
        ret ^= nums[i];
    
    int mask = 1;
    while ((ret & mask) == 0) 
        mask <<= 1;
    
    int a = 0, b = 0;
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & mask) == 0)
            a ^= nums[i];
        else 
            b ^= nums[i];
    }
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = a;
    res[1] = b;
    *returnSize = 2;
    return res;
}