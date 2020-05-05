#include <stdio.h>
#include <math.h>

int cuttingRope(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int a = 1;
    while (n > 4) {
        a *= 3;
        n -= 3;
    }
    return a * n;
}

int cuttingRope1(int n) {
    if (n <= 3) return n - 1;
    int a = n / 3, b = n % 3;
    if (b == 0) return pow(3.0, a);
    if (b == 1) return pow(3.0, a - 1) * 4;
    return pow(3.0, a) * 2;
}

// compile add "-lm"
int main(void) {
    printf("%d\n", cuttingRope(2));
}