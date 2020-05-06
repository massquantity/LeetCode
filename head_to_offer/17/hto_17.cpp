class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        long long N = pow(10, n);
        for (long long i = 1; i < N; ++i)
            res.push_back(i);
        return res;
    }
};