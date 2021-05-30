func minArray(numbers []int) int {
    if len(numbers) == 1 {
        return numbers[0]
    }
    lo, hi := 0, len(numbers) - 1
    for lo < hi {
        mid := (lo + hi) >> 1
        if numbers[mid] < numbers[hi] {
            hi = mid
        } else if numbers[mid] > numbers[hi] {
            lo = mid + 1
        } else {
            hi--
        }
    }
    return numbers[lo]
}
