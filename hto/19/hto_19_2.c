#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool dp(int i, int j, int *memo, char *s, char *p) {
    bool res;
    int num = i * 40 + j;
    if (memo[num] == 1) return true;
    if (memo[num] == -1) return false;
    if (j == strlen(p)) return i == strlen(s);
    bool first_match = i < strlen(s) && (*(p + j) == *(s + i) || *(p + j) == '.');
    if (*(p + j + 1) == '*')
        res = dp(i, j + 2, memo, s, p) || (first_match && dp(i + 1, j, memo, s, p));
    else
        res = first_match && dp(i + 1, j + 1, memo, s, p);
    memo[num] = res ? 1 : -1;
    return res;
}

bool isMatch(char *s, char *p) {
    int *memo = calloc(1024, sizeof(int));
    return dp(0, 0, memo, s, p);
}

int main(void) {
    char *s = "mississippi";
    char *p = "mis*is*p*.";
    printf("%s\n", isMatch(s, p) ? "true" : "false");
}