#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < left) {
                ++res;
                left = min(left, intervals[i][1]);
            } else {
                left = intervals[i][1];
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> a{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution s;
    cout << s.eraseOverlapIntervals(a) << endl;
}
