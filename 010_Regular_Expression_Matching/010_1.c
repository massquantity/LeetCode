#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    if (!*p) return !*s;
    bool first_match = *s && (*s == *p || *p == '.');
    if (strlen(p) >= 2 && *(p + 1) == '*')
        return isMatch(s, p + 2) || (first_match && isMatch(s + 1, p));
    else
        return first_match && isMatch(s + 1, p + 1);
}

int main(void) {
    char *s = "aab";
    char *p = "*";
    printf("%s\n", isMatch(s, p) ? "true" : "false");
}

