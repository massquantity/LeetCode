class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int j = nums.size() - 2;
        while (j >= 0 && nums[j] >= nums[j + 1]) j--;
        if (j >= 0) {
            int k = nums.size() - 1;
            while (k >= j && nums[k] <= nums[j]) k--;
            swap(nums[k], nums[j]);
        }
        reverse(nums, j + 1, nums.size() - 1);
    }

private:
    void reverse(vector<int> &nums, int i, int j) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};