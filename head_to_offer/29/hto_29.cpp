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
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> res;
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        while (true) {
            for (int i = l; i <= r; i++) res.emplace_back(matrix[t][i]);
            if (++t > b) break;
            for (int i = t; i <= b; i++) res.emplace_back(matrix[i][r]);
            if (l > --r) break;
            for (int i = r; i >= l; i--) res.emplace_back(matrix[b][i]);
            if (--b < t) break;
            for (int i = b; i >= t; i--) res.emplace_back(matrix[i][l]);
            if (++l > r) break;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for (int i : res) {
        cout << i << " ";
    }
}


