class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        size_t len = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[i]) break;
                if (!dp[j]) continue;
                string subs = s.substr(j, i - j);
                if (wordSet.find(subs) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
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
