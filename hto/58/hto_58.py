import re

class Solution:
    def reverseWords(self, s: str) -> str:
        s_list = re.split(r"\s+", s.strip())
        s_list.reverse()
        return " ".join(s_list)

