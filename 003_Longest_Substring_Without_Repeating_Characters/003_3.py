class Solution:
    def lengthOfLongestSubstring(self, s):
        length = 0
        left = 0
        last = {}

        for i, char in enumerate(s):
            if char in last and last[char] >= left:
                left = last[char] + 1
            last[char] = i
            length = max(length, i - left + 1)
        return length