#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

char * multiply(char * num1, char * num2){
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) return "0";
    size_t len1 = strlen(num1), len2 = strlen(num2);
    int mult[len1 + len2];
    memset(mult, 0, sizeof(mult));
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int m = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = m + mult[p2];
            mult[p2] = sum % 10;
            mult[p1] += sum / 10;
        }
    }

    int k = 0;
    while (!mult[k] && k < len1 + len2) k++;
    size_t length = len1 + len2 - k;
    char *res = (char *)malloc(sizeof(char) * (length + 1));
    int i = 0;
    while (i < length) {
        res[i++] = mult[k++] + '0';
    }
    res[i] = '\0';
    return res;
}


int main(void) {
    printf("%s\n", multiply("2", "3"));
}

