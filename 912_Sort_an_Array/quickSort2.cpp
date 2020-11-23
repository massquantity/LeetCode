#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        sortArray(nums, 0, len - 1);
        return nums;
    }

    void sortArray(vector<int> &nums, int lo, int hi) {
        if (hi <= lo) return;
        int v = nums[lo];
        int i = lo + 1, j = hi;
        while (true) {
            while (nums[i] <= v && i < hi) i++;
            while (nums[j] > v && j >= lo) j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        nums[lo] = nums[j];
        nums[j] = v;
        sortArray(nums, lo, j - 1);
        sortArray(nums, j + 1, hi);
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
