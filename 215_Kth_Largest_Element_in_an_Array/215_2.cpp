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
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        quickSearch(nums, 0, nums.size() - 1, target);
        return nums[target];
    }

private:
    void quickSearch(vector<int> &nums, int lo, int hi, int k) {
        int r = rand() % (hi - lo + 1) + lo;
        swap(nums[r], nums[lo]);

        int p = partition(nums, lo, hi);
        if (p == k) return;
        else if (p > k) quickSearch(nums, lo, p - 1, k);
        else if (p < k) quickSearch(nums, p + 1, hi, k);
    }

    int partition(vector<int> &nums, int lo, int hi) {
        int v = nums[lo];
        int i = 0, j = hi + 1;
        while (true) {
            while (++i <= hi && nums[i] <= v);
            while (--j > lo && nums[j] >= v);
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
    vector<int> v {-1, -1};
    cout << s.findKthLargest(v, 2) << endl;
}

