void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int k = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0) {
        nums1[k--] = nums2[n] > nums1[m] ? nums2[n--] : nums1[m--];
    }
   // while (n >= 0) {
   //     nums1[k--] = nums2[n--];
   // }
    if (n >= 0)
        memcpy(nums1, nums2, (n+1) * sizeof(int));
}
