class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        long a = 1, b = 1;
        for (int i = 2; i <= s.size(); i++) {
            string tmp = s.substr(i - 2, 2);
            long c = (tmp >= "10" && tmp <= "25") ? a + b : a;
            b = a;
            a = c;
        }
        return a;
    }
};