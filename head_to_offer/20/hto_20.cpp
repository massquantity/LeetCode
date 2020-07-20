#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <map>
#include <stack>
#include <bitset>
#include <array>
using namespace std;

typedef unordered_map<char, int> trans;

class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<char, int>> states;
        states.emplace_back(trans({
            {' ', 0}, {'s', 1}, {'d', 2}, {'.', 4}
        }));
        states.emplace_back(trans({{'d', 2}, {'.', 4}}));
        states.emplace_back(trans({
            {'d', 2}, {'.', 3}, {'e', 5}, {' ', 8}
        }));
        states.emplace_back(trans({
            {'d', 3}, {'e', 5}, {' ', 8}
        }));
        states.emplace_back(trans({{'d', 3}}));
        states.emplace_back(trans({{'s', 6}, {'d', 7}}));
        states.emplace_back(trans({{'d', 7}}));
        states.emplace_back(trans({{'d', 7}, {' ', 8}}));
        states.emplace_back(trans({{' ', 8}}));

        int p = 0;
        char t;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') t = 'd';
            else if (c == '+' || c == '-') t = 's';
            else if (c == '.' || c == 'e' || c == 'E' || c == ' ') t = c;
            else t = '?';
            if (states[p].find(t) == states[p].end()) return false;
            p = states[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};

int main() {
    Solution s;
    string test = "5e2";
    string test1 = "1a3.14";
    string test2 = "12e+5.4";
    cout << boolalpha << s.isNumber(test) <<
        " " << s.isNumber(test1) <<
        " " << s.isNumber(test2) << endl;
}
