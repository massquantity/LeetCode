#define LIMIT 0x80000000

int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    bool negative = (dividend ^ divisor) < 0;
    unsigned int t = dividend == INT_MIN ? LIMIT : abs(dividend);
    unsigned int d = divisor == INT_MIN ? LIMIT : abs(divisor);
    unsigned int res = 0;
    for (int i = 31; i >= 0; i--) {
        if ((t >> i) >= d) {
            res += ((unsigned int) 1) << i;
            t -= d << i;
        }
    }

    if (res == LIMIT) return INT_MIN;
    else return negative ? -(int)res : (int)res;
}

