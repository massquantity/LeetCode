class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi])
                hi = mid;
            else if (nums[mid] > nums[hi])
                lo = mid + 1;
        }
        return nums[lo];
    }
};

int main() {
    vector<int> v{3,4,5,1,2};
    Solution s;
    cout << s.findMin(v) << endl;
}