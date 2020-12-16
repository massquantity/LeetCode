from typing import List, Dict

class Solution(object):
    def longestSubstring(self, s, k):
        if len(s) < k:
            return 0
        c = min(set(s), key=s.count)
        if s.count(c) >= k:
            return len(s)
        return max(self.longestSubstring(t, k) for t in s.split(c))


if __name__ == "__main__":
    print(Solution().longestSubstring("ababbc", 2))
