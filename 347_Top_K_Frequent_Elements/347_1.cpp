class Solution {
public:
    unordered_map<int, int> map;
    vector<int> res;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int n : nums) 
            map[n]++;
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (res.size() < k) {
                res.emplace_back(it->first);
                swim(res.size() - 1);
            } else {
                if (it->second > map[res[0]]) {
                    res[0] = it->first;
                    sink(0);
                }
            }
        }
        return res;
    }

    void swim(int k) {
        while (k > 0) {
            int j = (k - 1) >> 1;
            if (map[res[j]] <= map[res[k]]) break;
            swap(res[j], res[k]);
            k = j;
        }
    }

    void sink(int k) {
        int n = res.size();
        while (2*k + 1 < n) {
            int j = 2*k + 1;
            if (j < n - 1 && map[res[j]] > map[res[j+1]]) j++;
            if (map[res[k]] <= map[res[j]]) break;
            swap(res[j], res[k]);
            k = j;
        }
    }
};
