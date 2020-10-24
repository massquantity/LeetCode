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

struct compare {
    bool operator() (vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
} myCompare;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), myCompare);
        for (vector<int> &arr : intervals) {
            if (res.empty() || res.back()[1] < arr.front()) {
                res.push_back(arr);
            } else {
                res.back()[1] = max(res.back()[1], arr.back());
            }
        }
        return res;
    }
};



int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution so;
    for(auto &v : so.merge(intervals)) {
        for (int &i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

