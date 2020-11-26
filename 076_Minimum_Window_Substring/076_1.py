from typing import List, Dict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""
        t_freq = [0 for _ in range(128)]
        for c in t:
            t_freq[ord(c)] += 1
        
        i = 0
        distance = len(t)
        left = 0
        right = len(s) + 1
        for j, c in enumerate(s):
            c_right = ord(c)
            if t_freq[c_right] > 0:
                distance -= 1
            t_freq[c_right] -= 1
            
            if distance == 0:
                while True:
                    c_left = ord(s[i])
                    if t_freq[c_left] == 0:
                        break
                    else:
                        t_freq[c_left] += 1
                        i += 1
                
                if j - i < right - left:
                    left, right = i, j
                t_freq[ord(s[i])] += 1
                distance += 1
                i += 1
        
        return "" if right == len(s) + 1 else s[left: right+1]


if __name__ == "__main__":
    s = Solution()
    print(s.minWindow("ADOBECODEBANC", "ABC"))
