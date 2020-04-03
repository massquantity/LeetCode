#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

struct compare2 {
    bool operator() (vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
} myCompare;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), myCompare);
        int end = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) count++;
            else                       end = intervals[i][1];
        }
        return count;
    }
};


int main() {
    vector<vector<int>> a{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution s;
    cout << s.eraseOverlapIntervals(a) << endl;
}
