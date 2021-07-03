func cuttingRope(n int) int {
    if n <= 3 {
        return n - 1
    }
    res := 1
    for n > 4 {
        res *= 3
        n -= 3
    }
    return res * n
}
