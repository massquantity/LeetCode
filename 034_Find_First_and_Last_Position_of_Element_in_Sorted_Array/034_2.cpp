class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start, end;
        if (nums.empty()) return {-1, -1};
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
        if (lo == nums.size()) start = -1;
        else start = nums[lo] == target ? lo : -1;

        hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (target >= nums[mid])
                lo = mid + 1;
            else
                hi = mid;
        }
        if (hi == 0)  end = -1;
        else  end = nums[hi - 1] == target ? hi - 1 : -1;
        return {start, end};
    }
};