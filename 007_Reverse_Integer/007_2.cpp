class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        long long res;
        if (x < 0)
            res = -1 * stoll(s);
        else
            res = stoll(s);
        if (abs(res) > INT_MAX) return 0;
        else                    return (int)res;
    }
};