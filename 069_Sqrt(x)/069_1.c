int mySqrt(int x){
    if (x == 0) return 0;
    if (x == 1) return 1;
    long lo = 0, hi = x;
    while (lo < hi) {
        long mid = (lo + hi) >> 1;
        long squ = pow(mid, 2);
        if (squ < x) {
            lo = mid + 1;
        } else if (squ > x) {
            hi = mid;
        } else {
            return (int)mid;
        }
    }
    return (int)lo - 1;
}

int mySqrt2(int x){
    if (x == 0) return 0;
    if (x == 1) return 1;
    long lo = 0, hi = x;
    while (lo < hi) {
        long mid = (lo + hi + 1) >> 1;
        long squ = pow(mid, 2);
        if (squ < x) {
            lo = mid;
        } else if (squ > x) {
            hi = mid - 1;
        } else {
            return (int)mid;
        }
    }
    return (int)lo;
}