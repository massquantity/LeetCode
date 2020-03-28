#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * commonPrefix(char *left, char *right) {
    size_t min = strlen(left) > strlen(right) ? strlen(right) : strlen(left);
    char *minp = strlen(left) > strlen(right) ? right : left;
    char *res1, *res2;
    for (int i = 0; i < min; ++i) {
        if (left[i] != right[i]) {
            if (i == 0) return "";
            res1 = (char *)malloc(sizeof(char) * i);
            strncpy(res1, minp, i);
            return res1;
        }
    }
    res2 = (char *)malloc(sizeof(char) * min);
    strncpy(res2, minp, min);
    return res2;
}

char * shortCommonPrefix(char ** strs, int l, int r) {
    if (l == r) return strs[l];
    int mid = (l + r) / 2;
    char *lcpLeft  = shortCommonPrefix(strs, l, mid);
    char *lcpRight = shortCommonPrefix(strs, mid + 1, r);
    return commonPrefix(lcpLeft, lcpRight);
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strs == NULL) return NULL;
    return shortCommonPrefix(strs, 0, strsSize - 1);
}


int main(void) {
    char **strs = (char **)malloc(sizeof(char *) * 3);
    strs[0] = "flower";
    strs[1] = "flow";
    strs[2] = "flight";
    printf("%s\n", longestCommonPrefix(strs, 3));
//    printf("%c\n", strs[0][0]);
//    printf("%lu\n", strlen(strs));
}

