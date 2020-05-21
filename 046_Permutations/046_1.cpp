#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        deque<int> track; 
        backtrack(nums, track, res);
        return res;
    }

private:
    void backtrack(vector<int> &nums, deque<int> &track, vector<vector<int>> &res) {
        if (track.size() == nums.size()) {
            res.emplace_back(vector<int>(track.begin(), track.end()));
            return;
        }

        for (int &n : nums) {
            if (find(track.cbegin(), track.cend(), n) != track.end()) continue;
            track.push_back(n);
            backtrack(nums, track, res);
            track.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    for (auto & i : s.permute(nums)) {
        for (auto & j : i)
            cout << j << " ";
        cout << "\n";
    }
}
