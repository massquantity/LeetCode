from typing import List, Dict

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        res = []
        tmp = []

        def is_valid(begin, end) -> bool:
            if s[begin] == '0' and end - begin > 1:
                return False
            num = 0
            for i in range(begin, end):
                num = num * 10 + ord(s[i]) - ord('0')
            return 0 <= num <= 255

        def dfs(idx, count) -> None:
            if count >= 4:
                if count == 4 and idx == n:
                    res.append(".".join(tmp))
                return 

            for i in range(idx, idx + 3):
                if n - i > 3 * (4 - count):
                    break
                if i >= n:
                    break
                if is_valid(idx, i+1):
                    tmp.append(s[idx: i+1])
                    dfs(i + 1, count + 1)
                    tmp.pop()

        dfs(0, 0)
        return res   
                

if __name__ == "__main__":
    print(Solution().restoreIpAddresses("25525511135"))
