func fib(n int) int {
    if n < 2 {
        return n
    } else {
        a, b := 0, 1
        for i := 0; i < n - 1; i++ {
            tmp := (a + b) % (1e9 + 7)
            a, b = b, tmp
        }
        return b
    }
}

func fib(n int) int {
    if n < 2 {
        return n
    } else {
        a, b := 0, 1
        for i := 0; i < n - 1; i++ {
            b += a
            a = b - a
            b %= (1e9 + 7)
        }
        return b
    }
}
