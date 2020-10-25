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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string> > m;
        for (string &s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s);
        }
        for (auto &&n : m) {
            res.push_back(n.second);
        }
        return res;
    }
};


int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    for (auto ss: s.groupAnagrams(strs)) {
        for (string sss : ss)
            cout << sss << " ";
        cout << "\n";
    }
}

