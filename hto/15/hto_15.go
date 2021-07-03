func hammingWeight(num uint32) int {
    count := 0
    var flag uint32 = 1
    for flag > 0 {
        if num & flag > 0 {
            count++
        }
        flag <<= 1
    }
    return count
} 

func hammingWeight(num uint32) int {
    count := 0
    for num > 0 {
        count++
        num &= (num-1)
    }
    return count
}
