#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        size_t minLen = INT_MAX;
        for (const auto &s : strs)
            minLen = s.size() < minLen ? s.size() : minLen;
        /*
        int low = 0, high = minLen;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isCommonPrefix(strs, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return strs[0].substr(0, (low + high) / 2);
        */
        int low = 0, high = minLen + 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isCommonPrefix(strs, mid))
                low = mid + 1;
            else
                high = mid;
        }
        return strs[0].substr(0, low - 1);
    }

    bool isCommonPrefix(vector<string> &strs, int mid) {
        string first = strs[0].substr(0, mid);
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].find(first, 0) != 0)
                return false;
        }
        return true;
    }
};


int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
}