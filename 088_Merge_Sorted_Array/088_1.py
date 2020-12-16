from typing import List, Dict

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        def binary_search(target, lo, hi):
            while lo < hi:
                mid = (lo + hi) >> 1
                if target <= nums1[mid]:
                    hi = mid
                elif target > nums1[mid]:
                    lo = mid + 1
            return lo

        k = 0
        for i in range(n):
            k = binary_search(nums2[i], k, m)
            for j in range(m, k, -1):
                nums1[j] = nums1[j-1]
            nums1[k] = nums2[i]
            m += 1


if __name__ == "__main__":
    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    Solution().merge(nums1, 3, nums2, 3)
    print(nums1)
