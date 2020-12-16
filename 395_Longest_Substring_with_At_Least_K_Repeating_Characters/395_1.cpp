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
#include <omp.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        unordered_map<char, int> map;
        for (char c : s) map[c]++;
        vector<int> split;
        for (int i = 0; i < n; i++) {
            if (map[s[i]] < k) split.emplace_back(i);
        }
        if (split.empty()) return n;
        split.emplace_back(n);
        int res = 0, left = 0;
        for (int sp : split) {
            int len = sp - left;
            if (len > res)
                return max(res, longestSubstring(s.substr(left, len), k));
            left = sp + 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.longestSubstring("ababbc", 2) << endl;
}
