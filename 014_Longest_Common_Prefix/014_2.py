from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        ss = list(map(set, zip(*strs)))
        res = ""
        for x in ss:
            x = list(x)
            if len(x) > 1:
                break
            res += x[0]
        return res


if __name__ == "__main__":
    strs = ["flow", "flower", "flight"]
    s = Solution()
    print(s.longestCommonPrefix(strs))