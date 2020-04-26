int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    for (int i = 0; i < n - 1; ++i) {
        int tmp = (a + b) % (int)(1e9 + 7);
        a = b;
        b = tmp;
    }
    return b;
}

int fib2(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    for (int i = 0; i < n - 1; ++i) {
        b += a;
        a = b - a;
        b %= 1000000007;
    }
    return b;
}

int main(int argc, char *argv[])
{
    printf("%d\n", fib(95));
}