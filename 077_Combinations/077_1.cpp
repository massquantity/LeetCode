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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n < k) return res;
        vector<int> track;
        backtrack(1, n, k, track, res);
        return res;
    }

    void backtrack(int cur, int n, int k, vector<int> &track, vector<vector<int>> &res) {
        if (track.size() + (n - cur + 1) < k) {
            return;
        }

        if (track.size() == k) {
            res.emplace_back(move(vector<int>(track.cbegin(), track.cend())));
            return;
        }

        for (int i = cur; i <= n; i++) {
            track.push_back(i);
            backtrack(i + 1, n, k, track, res);
            track.pop_back();
        }
    }
};

int main() {
    Solution s;
    for (const vector<int>& v : s.combine(4, 2)) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
