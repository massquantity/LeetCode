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
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < m; ++i) obstacleGrid[i][0] =
                (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        for (int j = 1; j < n; ++j) obstacleGrid[0][j] =
                (obstacleGrid[0][j] == 0 && obstacleGrid[0][j - 1] == 1) ? 1 : 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid.back().back();
    }
};


int main() {
    vector<vector<int>> aa(3, vector<int>(3, 0));
    aa[1][1] = 1;
    Solution s;
    cout << s.uniquePathsWithObstacles(aa) << endl;
}
