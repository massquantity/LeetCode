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
    string convert(string s, int numRows) {
        size_t len = s.size();
        if (len == 0 || numRows < 1) return "";
        if (numRows == 1) return s;
        vector<string> tmp(numRows, "");
        int divide = 2 * (numRows - 1);
        for (int i = 0; i < len; i++) {
            int remainder= i % divide;
            if (remainder < numRows - 1)
                tmp[remainder].push_back(s[i]);
            else
                tmp[divide - remainder].push_back(s[i]);
        }
        string res;
        for (int i = 0; i < numRows; i++) {
            res += tmp[i];
        }
        return res;
    }
};


int main() {
    Solution s;
    string str = "LEETCODEISHIRING";
    cout << s.convert(str, 4) << endl;
}




