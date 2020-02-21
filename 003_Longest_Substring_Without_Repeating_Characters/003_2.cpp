class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = 0, i = 0, j = 0;
		unordered_set<char> pool;
        int size = (int)s.size();
		while (j < size && i < size) {
			if (pool.find(s[j]) == pool.end()) {
				pool.insert(s[j++]);
				length = max(length, j - i);
			} else {
				pool.erase(s[i++]);
			}
		}
		return length;
	}
};