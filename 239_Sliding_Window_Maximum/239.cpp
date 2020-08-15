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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) return vector<int>{};
        vector<int> res;
        deque<int> queue;
        for (int i = 0; i < nums.size(); i++) {
            while (!queue.empty() && nums[queue.back()] < nums[i])
                queue.pop_back();
            queue.push_back(i);
            if (!queue.empty() && i - queue.front() == k)
                queue.pop_front();
            if (i >= k - 1) res.push_back(nums[queue.front()]);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v {1,3,-1,-3,5,3,6,7};
    for (int i : s.maxSlidingWindow(v, 3)) {
        cout << i << " ";
    }
}

