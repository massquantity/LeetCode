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
        int i = rand() % (hi - lo + 1) + lo;
        swap(nums[lo], nums[i]);
        int p = partition(nums, lo, hi);
        sortArray(nums, lo, p - 1);
        sortArray(nums, p + 1, hi);
    }

    int partition(vector<int> &nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo + 1, j = hi;
        while (true) {
            while (nums[i] <= v) {
                i++;
                if (i > hi) break;
            }
            while (nums[j] > v) {
                j--;
                if (j == lo) break;
            }
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        nums[lo] = nums[j];
        nums[j] = v;
        return j;
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
