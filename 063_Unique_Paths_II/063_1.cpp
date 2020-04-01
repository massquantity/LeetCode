#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1)return 0;
        size_t m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<u_int32_t>> dp(m, vector<u_int32_t>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 && j == 0) dp[i][j] = 1;
                    else if (i == 0)      dp[i][j] = dp[i][j - 1];
                    else if (j == 0)      dp[i][j] = dp[i - 1][j];
                    else    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};


int main() {
    vector<vector<int>> aa(3, vector<int>(3, 0));
    aa[1][1] = 1;
    Solution s;
    cout << s.uniquePathsWithObstacles(aa) << endl;
}
