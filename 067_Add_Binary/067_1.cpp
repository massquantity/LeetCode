class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        int carry = 0;
        string res;
        for (int i = 0; i < n; i++) {
            carry += i < a.size() ? a[a.size() - 1 - i] - '0' : 0;
            carry += i < b.size() ? b[b.size() - 1 - i] - '0' : 0;
            res.push_back(carry % 2 + '0');
            carry /= 2;
        }

        if (carry == 1) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};