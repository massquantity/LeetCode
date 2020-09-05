int strStr(char * haystack, char * needle) {
    if (*needle == '\0') return 0;
    int m = strlen(haystack), n = strlen(needle);
    if (m < n) return -1;
    for (int i = 0; i <= m - n; i++) {
        for (int j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) break;
            if (j == n - 1) return i;
        }
    }
    return -1;
}