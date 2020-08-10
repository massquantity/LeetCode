from typing import List

class Solution:
    def replaceSpace(self, s: str) -> str:
        res = []
        for c in s:
            if c == ' ':
                res.append("%20")
            else:
                res.append(c)
        return ''.join(res)

    def replaceSpace2(self, s: str) -> str:
        return ''.join(("%20" if c == ' ' else c for c in s))


if __name__ == "__main__":
    s = Solution()
    print(s.replaceSpace("We are happy"))
    print(s.replaceSpace2("You are sad"))