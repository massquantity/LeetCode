class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] - 1 < n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
