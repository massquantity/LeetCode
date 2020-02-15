class Solution {
public:
    vector<int> towSum(vector<int> & nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if (m.find(other) != m.end())
                return vector<int> {m[other], i};
            m[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> v {2, 7, 11, 15};
    Solution s;
    cout << s.towSum(v, 9).empty() << endl;
    for (int f : s.towSum(v, 9))
        cout << f << " ";
}