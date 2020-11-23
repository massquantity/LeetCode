#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2; i >= 0; i--) {
            heapify(nums, i, n);
        }
        while (n > 0) {
            swap(nums[0], nums[n - 1]);
            n--;
            heapify(nums, 0, n);
        }
        return nums;
    }

    void heapify(vector<int> &nums, int k, int n) {
        while (2*k + 1 < n) {
            int j = 2*k + 1;
            if (j < n - 1 && nums[j] < nums[j+1]) j++;
            if (nums[j] <= nums[k]) break;
            swap(nums[j], nums[k]);
            k = j;
        }
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
