class Solution:
    def reverse(self, x):
        if x < 0:
            res = -1 * int(str(-x)[::-1])
        else:
            res = int(str(x)[::-1])

        if abs(res) > 0x7fffffff:
            return 0
        return res