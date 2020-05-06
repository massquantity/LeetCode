#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

double fastPow(double x, long long n) {
    if (n == 0) return 1.0;
    double half = fastPow(x, n >> 1);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

double myPow(double x, int n){
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    return fastPow(x, N);
}

int main(void) {
    printf("%f\n", myPow(2.0, 10));
}

