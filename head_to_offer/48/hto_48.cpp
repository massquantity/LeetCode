class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t len = s.size();
        if (s.empty()) return 0;
        if (len == 1) return 1;
        int res = 0;
        int i = 0, j = 1;
        string word;
        while (j < len) {
            word = s.substr(i, j - i);
			if (word.find(s[j]) != string::npos) {
				res = max(res, j - i);
				i = s.find(s[j], i) + 1;
				j = i + 1;
            } else {
                res = max(res, j - i + 1);
                j++;
            }
        }
        return res;
    }
};