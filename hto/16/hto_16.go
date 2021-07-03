func myPow(x float64, n int) float64 {
    if n < 0 {
        return 1.0 / fastPow(x, -n)
    }
    return fastPow(x, n)
}

func fastPow(x float64, n int) float64 {
    if n == 0 {
        return 1.0
    }
    half := fastPow(x, n / 2)
    if n % 2 == 1 {
        return half * half * x
    }
    return half * half
}

func myPow(x float64, n int) float64 {
    if n == 0 {
        return 1
    } 
    if n == 1 {
        return x
    }
    if n == -1 {
        return 1.0 / x
    }
    half := myPow(x, n >> 1)
    rest := myPow(x, n & 1)
    return half * half * rest
}
