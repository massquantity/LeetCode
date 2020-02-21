class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = 0;
		unordered_map<char, int> map;
		int size = (int)s.size();
		for (int i = 0, j = 0; j < size; ++j) {
			if (map.find(s[j]) != map.end())
				i = max(map[s[j]] + 1, i);
			map[s[j]] = j;
			length = max(length, j - i + 1);
		}
        return length;
	}
};