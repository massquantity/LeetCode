from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        if m == 0:
            for i in range(n):
                nums1[i] = nums2[i]
            return
        if n == 0:
            return

        for n in nums2:
            j = m
            while j > 0 and n < nums1[j-1]:
                nums1[j] = nums1[j-1]
                j -= 1
            nums1[j] = n
            m += 1