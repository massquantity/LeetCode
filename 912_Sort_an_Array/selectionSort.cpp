#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int min = i;
            for (int j = i + 1; j < len; j++) {
                if (nums[j] < nums[min]) min = j;
            }
            swap(nums[i], nums[min]);
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
