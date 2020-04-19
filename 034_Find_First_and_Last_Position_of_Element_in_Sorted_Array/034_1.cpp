class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        if (nums.size() == 1) {
            if (target == nums[0]) return {0, 0};
            else                   return {-1, -1};
        }
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (target <= nums[mid])
                hi = mid;
            else 
                lo = mid + 1;
        }
        if (lo == nums.size() || nums[lo] != target) return res;
        res[0] = lo;

        hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (target >= nums[mid])
                lo = mid + 1;
            else
                hi = mid;
        }
        res[1] = hi - 1;
        return res;
    }
};