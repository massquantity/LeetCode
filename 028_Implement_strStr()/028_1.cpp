class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle)
                return i;
        }
        return -1;
    }
};



