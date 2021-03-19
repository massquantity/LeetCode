class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        list<vector<int>> res;
        for (auto &e : people) {
            auto pos = res.begin();
            advance(pos, e[1]);
            res.insert(pos, e);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
