class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        whole = nums1 + nums2
        ll = len(whole)
        whole.sort()
        if ll % 2 == 0 and ll != 0:
            return (whole[ll // 2 - 1] + whole[ll // 2]) / 2.0
        else:
            return float(whole[ll // 2])