class Solution {
public:
    // 超时
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S > sum) return 0;
        if ((sum + S) % 2 != 0) return 0;
        int target = (sum + S) / 2;
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, res, tmp, target, 0);
        return res.size();
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &tmp, int target, int idx) {
        if (target == 0) {
            res.push_back(tmp);
        } 
        if (idx == nums.size() || target < 0) return;
        for (int i = idx; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            dfs(nums, res, tmp, target - nums[i], i + 1);
            tmp.pop_back();
        }
    }
};
