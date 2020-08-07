class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1
        res = 0
        i = 0
        j = 1
        while j < len(s):
            word = s[i:j]
            if s[j] in word:
                res = max(res, j - i)
                i = s.find(s[j], i, j) + 1
                j = i + 1
            else:
                res = max(res, j - i + 1)
                j += 1
        return res

