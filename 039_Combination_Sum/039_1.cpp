#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(tmp, candidates, target, 0);
        return res;
    }

    void dfs(vector<int> &tmp, vector<int> &candidates, int target, int begin) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            if (target - candidates[i] < 0) break;
            tmp.push_back(candidates[i]);
            dfs(tmp, candidates, target - candidates[i], i);
            tmp.pop_back();
        }
    }

private:
    vector<vector<int>> res;
};


int main() {
    vector<int> c = {2, 3, 6, 7};
    Solution so;
    for (const vector<int>& v : so.combinationSum(c, 7)) {
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    }
}




