int candy(int* ratings, int ratingsSize){
    int tmp[ratingsSize];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < ratingsSize; ++i) {
        if (i > 0 && ratings[i] > ratings[i - 1]) 
            tmp[i] = tmp[i - 1] + 1;
        else
            tmp[i] = 1;
    }
    int res = 0, right = 0;
    for (int i = ratingsSize - 1; i >= 0; --i) {
        if (i < ratingsSize - 1 && ratings[i] > ratings[i + 1])
            right++;
        else
            right = 1;
        res += fmax(tmp[i], right);
    }
    return res;
}
