class Solution:
    def reverse(self, x):
        x = str(x)
        if x[0] == '-':
            res =  '-' + x[1:].rstrip()[::-1]
        else:
            res =  x.rstrip()[::-1]

        if -2**31 <= int(res) <= (2**31 -1):
            return int(res)
        else:
            return 0