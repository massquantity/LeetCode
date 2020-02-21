class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())     return 0;
		if (s.size() == 1) return 1;
		int length = 0;
		int i = 1;
		int j = 0;
		string word;
		int size = (int)s.size();
		while (i < size) {
		//    word = string(s.begin() + j, s.begin() + i);
			word = s.substr(j, i - j);
			int wordSize = (int)word.size();
			if (word.find(s[i]) != string::npos) {
				length = max(length, wordSize);
				j = s.find(s[i], j) + 1;
				i = j + 1;
			} else {
				length = max(length, wordSize + 1);
				i += 1;
			}
		}
		return length;
	}
};