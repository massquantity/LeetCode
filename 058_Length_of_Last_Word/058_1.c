#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int lengthOfLastWord(char * s){
    size_t len = strlen(s);
    if (len == 0) return 0;
    int count = 0;
    int i = len - 1;
    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    return count;
}


int main(void) {
    char *s = "World World";
    printf("%d\n", lengthOfLastWord(s));
}

