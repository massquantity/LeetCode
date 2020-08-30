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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string> &res, string tmp, int l, int r, int n) {
        if (l > n || r > n || r > l) return;
        if (l == n && r == n) {
            res.push_back(tmp);
            return;
        }
        if (l >= r) {
            backtrack(res, tmp + '(', l+1, r, n);
            backtrack(res, tmp + ')', l, r+ 1, n);
        }
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<string> res = s.generateParenthesis(3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}


