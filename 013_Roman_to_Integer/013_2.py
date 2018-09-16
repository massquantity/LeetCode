class Solution:
    def romanToInt(self, s):
        maps = {'I':1, 'V':5, 'X':10, 'L':50, 
                'C':100, 'D':500, 'M':1000}

        total = 0
        for i in range(len(s)):
            curr = maps[s[i]]
            if i < len(s) - 1 and curr < maps[s[i+1]]:
                total -= curr
            else:
                total += curr
        return total

aa = Solution()
print(aa.romanToInt("LVI"))