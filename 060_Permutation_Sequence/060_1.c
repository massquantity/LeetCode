int factorial(int n) {
  int num = 1;
  while (n > 0)
    num *= n--;
  return num;
}

void deleteItem(int *nums, int numsSize, int index) {
  while (index < numsSize - 1) {
    nums[index] = nums[index + 1];
    index++;
  }
}

char *getPermutation(int n, int k) {
  int i, j = 0, factor;
  int nums[n];
  k--;
  char *res = (char *)calloc(10, sizeof(char));
  for (i = 0; i < n; i++)  
    nums[i] = i + 1;
  for (i = 0; i < n; i++) {  
    factor = factorial(n - i - 1);
    res[j++] = nums[k / factor] + '0';
    deleteItem(nums, n - i, k / factor);  
    k %= factor;
  }
  return res;
}