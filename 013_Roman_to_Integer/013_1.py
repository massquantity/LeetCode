class Solution:
    def romanToInt(self, s):
        maps = {'I':1, 'V':5, 'X':10, 'L':50, 
                'C':100, 'D':500, 'M':1000}

        total = 0
        prev = 0
        for i in range(len(s)):
            curr = maps[s[i]]
            if curr > prev:
                total += curr - 2 * prev
            else:
                total += curr
            prev = curr
        return total