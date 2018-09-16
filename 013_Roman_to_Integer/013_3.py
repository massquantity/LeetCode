class Solution:
    def romanToInt(self, s):
        maps = {'I':1, 'V':5, 'X':10, 'L':50, 
                'C':100, 'D':500, 'M':1000}

        total = 0
        prev = 0
        for char in s:
            curr = maps.get(char)
            total += (curr - 2 * prev) if (curr > prev) else curr
            prev = curr
        return total