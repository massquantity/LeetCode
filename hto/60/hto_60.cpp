#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <bitset>
#include <array>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<int> dp(6*n+1, 0);
        vector<double> res;
        for (int i = 1; i <= n; i++) {
            for (int j = 6*i; j >= i; j--) {
                dp[j] = 0;
                if (i == 1) {
                    dp[j] = 1;
                    continue;
                }
                for (int k = 1; k <= 6; k++) {
                    if (j - k >= i - 1) dp[j] += dp[j - k];
                }
            }
        }
        double denominator = pow(6, n);
        for (int i = n; i <= 6*n; i++) {
            res.push_back(dp[i] / denominator);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<double> res = s.twoSum(2);
    for (double i : res) {
        cout << i << " ";
    }
}


