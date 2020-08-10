#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *replaceSpace(char *s){
    size_t i = strlen(s);
    size_t b = 0;
    for (int k = 0; s[k]; ++k) {
        if (s[k] == ' ') b++;
    }
    /*
    while (*s) {
        if (*s == ' ') b++;
        s++;   // s will become empty string
    }
     */

    size_t j = i + b * 2;
    char *res = (char *)malloc(sizeof(char) * (j + 1));
    res[j] = '\0';
    while (i) {
        if (s[i - 1] == ' ') {
            res[--j] = '0';
            res[--j] = '2';
            res[--j] = '%';
        } else {
            res[--j] = s[i - 1];
        }
        i--;
    }
    return res;
}

int main(int argc, char *argv[])
{
    char *s = "We are happy.";
    printf("%s\n", replaceSpace(s));
}