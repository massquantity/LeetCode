bool contain(char *substr, char **wordDict, int wordDictSize) {
    for (int i = 0; i < wordDictSize; i++) {
        if (strcmp(substr, wordDict[i]) == 0) 
            return true;
    }
    return false;
}

bool wordBreak(char *s, char **wordDict, int wordDictSize){
    size_t size = strlen(s);
    bool dp[size + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= size; i++) {
        if (dp[i]) break;
        for (int j = 0; j < i; j++) {
            if (!dp[j]) continue;
            int sub_len = i - j;
            char substr[sub_len + 1];
            memcpy(substr, &s[j], sub_len);
            substr[sub_len] = '\0';
            if (contain(substr, wordDict, wordDictSize)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[size];
}
