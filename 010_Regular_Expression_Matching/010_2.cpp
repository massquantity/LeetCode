#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return dp(0, 0, s, p);
    }

private:
    unordered_map<int, int> memo;

    bool dp(int i, int j, string s, string p) {
        bool res;
        int num = i * 100 + j;
        if (memo.find(num) != memo.end()) return memo[num];
        if (j == p.length()) return i == s.length();
        bool first_match = i < s.length() && (p[j] == s[i] || p[j] == '.');
        if (j <= p.length() - 2 && p[j + 1] == '*')
            res = dp(i, j + 2, s, p) ||
                    (first_match && dp(i + 1, j, s, p));
        else
            res = first_match && dp(i + 1, j + 1, s, p);
        memo[num] = res;
        return res;
    }
};

int main() {
    string str = "mississippi";
    string pattern = "mis*is*p*.";
    Solution s;
    cout << boolalpha << s.isMatch(str, pattern) << endl;
}