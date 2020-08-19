class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if (len == 0) return a;
        vector<int> res(len, 1);
        int left = 1, right = 1;
        for (int i = 0; i < len; i++) {
            res[i] *= left;
            left *= a[i];

            res[len - i - 1] *= right;
            right *= a[len - i - 1];
        } 
        return res;
    }
};