class Solution:
    def lengthOfLongestSubstring(self, s):
        if s == "":
            return 0
        if len(s) == 1:
            return 1
        length = 0
        i = 1
        j = 0
        while i < len(s):
            word = s[j:i]
            if s[i] in word:
                length = max(length, len(word))
                j = s.find(s[i], j, i) + 1
                i = j + 1
            else:
                length = max(length, len(word) + 1)
                i += 1
        return length