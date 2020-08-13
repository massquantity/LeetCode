class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int i = 1; 
        int sum = 3;
        int mid = target / 2 + 1;
        for (int j = 3; j <= mid; j++) {
            sum += j;
            while (sum > target) {
                sum -= i++;
            }
            if (sum == target) {
                tmp.clear();
                for (int k = i; k <= j; k++) {
                    tmp.push_back(k);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};