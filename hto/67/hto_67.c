#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int strToInt(char * str){
    size_t n = strlen(str);
    int i, sign, res;
    for (i = 0; isspace(str[i]); ++i);
    sign = str[i] == '-' ? -1 : 1;
    if (str[i] == '+' || str[i] == '-') i++;
    for (res = 0; isdigit(str[i]); ++i) {
        int tmp = str[i] - '0';  // 减去 '0' 的ASCII码
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp >= INT_MAX % 10))
            return INT_MAX;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && tmp >= -(INT_MIN % 10)))
            return INT_MIN;
        // 每一步都把符号位乘进去
        res = res * 10 + sign * tmp;
    }
    return res;
}

int main(void) {
    char *str1 = "-2147483647";
    char *str2 = "2147483648";
    char *str3 = "-91283472332";
    printf("%d %d %d\n", strToInt(str1), strToInt(str2), strToInt(str3));
}