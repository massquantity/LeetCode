#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string first = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(first, 0) != 0) {
                first = first.substr(0, first.size() - 1);
                if (first.empty()) return "";
            }
        }
        return first;
    }
};


int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
}