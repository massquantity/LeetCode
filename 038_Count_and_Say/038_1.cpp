class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string last = countAndSay(n - 1);
        int i = 0, j = 0;
        string res = "";
        while (j < last.size()) {
            while (last[i] == last[j] && j < last.size()) {
                j++;
            }
            res += to_string(j - i);
            res += last[i];
            i = j;
        }
        return res;
    }
};