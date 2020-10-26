class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        count = 0
        for i in reversed(range(len(s))):
            if s[i] == ' ':
                if count == 0:
                    continue
                break
            count += 1
        return count