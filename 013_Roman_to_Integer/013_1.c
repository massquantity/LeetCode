#include <stdio.h>

char roman[7] = "IVXLCDM";
int num[7] = {1, 5, 10, 50, 100, 500, 1000};

inline int map(char c) {
    for (int i = 0; i < 7; ++i) {
        if (roman[i] == c)
            return num[i];
    }
    return 0;
}

int romanToInt(char s[]){
    int i = 0, res = 0;
    while (s[i + 1] != '\0') {
        if (map(s[i]) >= map(s[i + 1]))
            res += map(s[i]);
        else
            res -= map(s[i]);
        i++;
    }
    res += map(s[i]);
    return res;
}

int main(void) {
    char s[] = "MCMXCIV";
    printf("%d\n", romanToInt(s));
}