class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        int i = s.size() - 1, j = i;
        string res;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--;
            j = i;
            while (i >= 0 && s[i] != ' ') i--;
            if (i < j) {
                res += s.substr(i + 1, j - i);
                res += " ";
            }
        }
        if (!res.empty()) res.pop_back();  // remove last white space
        return res;
    }
};