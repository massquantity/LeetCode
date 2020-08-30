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
        string tmp;
        int l, r;
        tuple<string, int, int> t;
        stack<tuple<string, int, int>> stack;
        stack.push(make_tuple("", 0, 0));
        while (!stack.empty()) {
            tie(tmp, l, r) = stack.top();
            stack.pop();
            if (l == n && r == n) {
                res.push_back(tmp);
                continue;
            }
            if (l < n) {
                stack.push(make_tuple(tmp + '(', l + 1, r));
            }
            if (r < l) {
                stack.push(make_tuple(tmp + ')', l, r + 1));
            }
        }
        return res;
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




