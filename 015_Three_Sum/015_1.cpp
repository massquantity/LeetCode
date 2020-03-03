class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(begin(nums), end(nums));
        int numsLength = nums.size();
        for (int i = 0; i < numsLength - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int j = i + 1;
                int k = numsLength - 1;
                while (j < k) { 
                    long threeSum = static_cast<long>(nums[i] + nums[j] + nums[k]);
                    if (threeSum == 0) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1]) j++;
	    				while (j < k && nums[k] == nums[k - 1]) k--;
	    				j++;
	    				k--;
                    } else if (threeSum < 0) {
                        ++j;
                    } else {
                        --k;
                    }
                }
            }
        }
        return res;
    }
};