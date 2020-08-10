class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (target <= nums[mid])
                hi = mid;
            else 
                lo = mid + 1;
        }
        if (lo == nums.size() || nums[lo] != target) return 0;
        int start = lo;

        hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (target >= nums[mid])
                lo = mid + 1;
            else
                hi = mid;
        }
        return hi - start;
    }
};