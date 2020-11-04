char * addBinary(char * a, char * b){
    int m = strlen(a), n = strlen(b);
    int carry = 0, i = m - 1, j = n - 1, k = 0;
    int max = m > n ? m : n;
    char *res = (char *)malloc(sizeof(char) * (max + 2));
    while (i >= 0 && j >= 0) {
        carry += a[i--] - '0';
        carry += b[j--] - '0';
        res[k++] = carry % 2 + '0';
        carry /= 2;
    }

    while (i >= 0) {
        carry += a[i--] - '0';
        res[k++] = carry % 2 + '0';
        carry /= 2;
    }
    
    while (j >= 0) {
        carry += b[j--] - '0';
        res[k++] = (carry % 2) + '0';
        carry /= 2;
    }  

    if (carry == 1) res[k++] = '1';
    res[k] = '\0';

    for (int t = 0; t < k / 2; t++) {
        char tmp = res[t];
        res[t] = res[k - 1 - t];
        res[k - 1 - t] = tmp;
    }
    return res;
}