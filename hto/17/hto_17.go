func printNumbers(n int) []int {
    res := []int{}
    max := int(math.Pow10(n))
    for i := 1; i < max; i++ {
        res = append(res, i)
    }
    return res
}
