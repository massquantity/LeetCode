#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) return -1;
        if (size == 1) return nums[0] == target ? 0 : -1;
        int lo = 0, hi = size;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[lo] < nums[mid]) {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid;
                else
                    lo = mid + 1;
            }
            else {
                if (target > nums[mid] && target < nums[lo])
                    lo = mid + 1;
                else
                    hi = mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution s;
    cout << s.search(nums, 7) << endl;
}
