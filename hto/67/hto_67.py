import re

class Solution:
    def strToInt(self, s: str) -> int:
        return max(min(int(*re.findall('^[\+\-]?\d+', s.lstrip())), 2**31 - 1), -2**31)

if __name__ == "__main__":
    s = Solution()
    s.strToInt("-91283472332")

