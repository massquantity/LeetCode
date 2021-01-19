class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        size_t len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 0; i < len; i++) {
            if (!dp[i]) continue;
            for (const auto &word: wordDict) {
                int wSize = word.size();
                if (i + wSize <= len && s.substr(i, wSize) == word)
                    dp[i + wSize] = true;
            }
        }
        return dp[len];
    }
};

int main() {
    Solution s;
    vector<string> wordDict{"leet", "code"};
    std::cout << boolalpha << s.wordBreak("leetcode", wordDict) << std::endl; 
}
