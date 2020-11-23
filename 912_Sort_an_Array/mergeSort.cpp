#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sortArray(nums, 0, nums.size() - 1);
        return nums;
    }

    void sortArray(vector<int> &nums, int lo, int hi) {
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sortArray(nums, lo, mid);
        sortArray(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }

    void merge(vector<int> &nums, int lo, int mid, int hi) {
        vector<int> aux(nums.size(), 0);
        for (int k = lo; k <= hi; k++) {
            aux[k] = nums[k];
        }

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)           nums[k] = aux[j++];
            else if (j > hi)            nums[k] = aux[i++];
            else if (aux[i] < aux[j])   nums[k] = aux[i++];
            else                        nums[k] = aux[j++];
        }
    }

    void merge2(vector<int> &nums, int lo, int mid, int hi) {
        vector<int> aux(nums.size(), 0);
        for (int k = lo; k <= hi; k++) {
            aux[k] = nums[k];
        }
        int i = lo, j = mid + 1, k = lo;
        while (i <= mid && j <= hi) {
            if (aux[i] < aux[j])  nums[k++] = aux[i++];
            else                  nums[k++] = aux[j++];
        }
        while (i <= mid) nums[k++] = aux[i++];
        while (j <= hi)  nums[k++] = aux[j++];
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
