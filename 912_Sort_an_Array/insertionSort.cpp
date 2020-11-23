#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j - 1])
                    swap(nums[j], nums[j - 1]);
                else
                    break;
            }
        }
        return nums;
    }

    vector<int> sortArray2(vector<int>& nums) {
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            int tmp = nums[i], j = i;
            while (j > 0 && tmp < nums[j - 1]) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = tmp;
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums {5,2,3,1,-1,-34,45};
    for (int i : s.sortArray2(nums)) {
        cout << i << " ";
    }
    cout << "\n";
}
