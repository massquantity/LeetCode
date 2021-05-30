func findMin(nums []int) int {
    lo, hi := 0, len(nums) - 1
    for lo < hi {
        mid := (lo + hi) >> 1
        if nums[mid] < nums[hi] {
            hi = mid
        } else if nums[mid] > nums[hi] {
            lo = mid + 1
        } else {
            hi--
        }
    }
    return nums[lo]
}
