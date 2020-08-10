class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
		int res = 0;
        unordered_map<char, int> map;
        for (int i = -1, j = 0; j < s.size(); j++) {
            if (map.find(s[j]) != map.end()) 
                i = max(map[s[j]], i);
            map[s[j]] = j;
            res = max(res, j - i);
        }
        return res;
	}
};