class Solution:
    def lengthOfLongestSubstring(self, s):
        if s == "":
            return 0
        if len(s) == 1:
            return 1
        length = 0
        right = 1
        left = 0
        while right < len(s):
            cur = s.find(s[right], left, right)
            if cur != -1:
                # length = max(length, right - left)
                if length < right - left:
                    length = right - left
                left = cur + 1
            right += 1
        if s[len(s)-1] not in s[left:len(s)-1]:
            return max(length, len(s) - left)
        return length