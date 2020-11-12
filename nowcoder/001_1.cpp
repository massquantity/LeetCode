class Solution {
public:
    string LCS(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxLen = 0, indexMax = 0;
        for (int i = 1; i <= m ; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;

                    if (maxLen < dp[i][j]) {
                        maxLen = dp[i][j];
                        indexMax = i;
                    }
                }

            }
        }
        cout << maxLen << endl;
        return maxLen == 0 ? "-1" : str1.substr(indexMax - maxLen, maxLen);
    }
};