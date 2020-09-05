int strStr(char * haystack, char * needle){
    if (*needle == '\0') return 0;
    int m = strlen(haystack), n = strlen(needle);
    if (m < n) return -1;
    for (int i = 0; i <= m - n; i++) {
        char s[n];
        strncpy(s, haystack + i, n);
        if (s == needle) return i;
    }
    return -1;
}