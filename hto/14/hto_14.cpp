#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= (n+1)/2; ++i) {
            for (int j = i; j <= n; ++j) {
                dp[j] = max(dp[j], i * dp[j-i]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.cuttingRope(10) << endl;
}
