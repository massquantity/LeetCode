 #include <stdint.h>
 
 int hammingWeight(uint32_t n) {
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (n & flag) count++;
        flag <<= 1;
    }
    return count;
}

int hammingWeight1(uint32_t n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n-1);
    }
    return count;
}

int main(void) {
    printf("%d\n", hammingWeight(100));
}