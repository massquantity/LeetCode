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
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> map {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res;
        string comb;
        backtrack(digits, 0, res, comb, map);
        return res;
    }

private:
    void backtrack(string& digits, int index, vector<string> &res,
            string &comb, unordered_map<char, string> map) {
        if (index == digits.size()) res.emplace_back(comb);
        else {
            char d = digits[index];
            string letters = map.at(d);
            for (const char &letter : letters) {
                comb.push_back(letter);
                backtrack(digits, index + 1, res, comb, map);
                comb.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    string str = "23";
    vector<string> res = s.letterCombinations(str);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}


