class Solution:
    def myAtoi(self, s: str) -> int:
        max_val = 2 ** 31 - 1
        min_val = -2 ** 31
        n = len(s)
        i = 0
        while i < n:
            if s[i].isspace():
                i += 1
            else:
                break
        if i == n:
            return 0
        
        sign = -1 if s[i] == '-' else 1
        if (s[i] == '+' or s[i] == '-'):
            i += 1

        res = 0
        while i < n:
            if not s[i].isdigit():
                break
            tmp = ord(s[i]) - ord('0')
            if sign == 1 and (res > max_val // 10 or (res == max_val // 10 and tmp >= max_val % 10)):
                return max_val
            if sign == -1 and (res > -min_val // 10 or (res == -min_val // 10 and tmp >= -min_val % 10)):
                return min_val
            res = res * 10 + tmp
            i += 1
        return res if sign == 1 else -res
