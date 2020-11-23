#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        int h = 1;
        while (h < len / 2) h = 3 * h + 1;
        while (h >= 1) {
            for (int i = h; i < len; i++) {
                for (int j = i; j >= h && nums[j] < nums[j - h]; j -= h) {
                    swap(nums[j], nums[j - h]);
                }
            }
            h /= 3;
        }
        return nums;
    }

    vector<int> sortArray2(vector<int>& nums) {
        int len = nums.size();
        for (int h = len / 2; h > 0; h /= 2) {
            for (int i = h; i < len; i++) {
                for (int j = i; j >= h && nums[j] < nums[j - h]; j -= h) {
                    swap(nums[j], nums[j - h]);
                }
            }
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums {5,2,3,1,-1,-34,45};
    for (int i : s.sortArray(nums)) {
        cout << i << " ";
    }
    cout << "\n";
}
