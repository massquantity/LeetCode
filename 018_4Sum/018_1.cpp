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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        size_t len = nums.size();
        if (nums.empty() || len < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++) {
            if (i == 0 || (i > 0 && nums[i - 1] < nums[i])) {
                for (int j = i + 1; j < len - 2; j++) {
                    if (j == i + 1 || (j > i + 1 && nums[j - 1] < nums[j])) {
                        int p = j + 1, q = len - 1;
                        while (p < q) {
                            int fSum = nums[i] + nums[j] + nums[p] + nums[q];
                            if (fSum == target) {
                                res.push_back({nums[i], nums[j], nums[p], nums[q]});
                                while (p < q && nums[p] == nums[p + 1]) p++;
                                while (p < q && nums[q] == nums[q - 1]) q--;
                                p++;
                                q--;
                            }
                            else if (fSum < target) p++;
                            else if (fSum > target) q--;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = s.fourSum(nums, 0);
    for (int i = 0; i < res.size(); i++) {
        for (int j : res[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

