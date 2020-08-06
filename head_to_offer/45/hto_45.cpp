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
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int &n : nums)
            strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), compare);
    //    sort(strs.begin(), strs.end(), [](string &a, string &b) { return a + b < b + a; });
        string res;
        for (string &s : strs)
            res += s;
        return res;
    }

private:
    static bool compare(const string &a, const string &b) {
        return a + b < b + a;
    }
};


int main() {
    Solution s;
    vector<int> v {3,30,34,5,9};
    cout << s.minNumber(v) << endl;
}

