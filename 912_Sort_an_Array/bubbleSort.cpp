#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
        }
        return nums;
    }

    vector<int> sortArray2(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            bool sorted = true;
            for (int j = 0; j < len - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    sorted = false;
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
            if (sorted) break;
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums {5,2,3,1};
    for (int i : s.sortArray(nums)) {
        cout << i << " ";
    }
    cout << "\n";
}
