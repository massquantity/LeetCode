bool wordBreak(char *s, char **wordDict, int wordDictSize){
    size_t size = strlen(s);
    bool dp[size + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= size; i++) {
        if (dp[i]) break;
        for (int j = 0; j < wordDictSize; j++) {
            size_t wlen = strlen(wordDict[j]);
            int k = i - wlen;
            if (k < 0) continue;
            if (dp[k] && !strncmp(s + k, wordDict[j], wlen)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[size];
}
