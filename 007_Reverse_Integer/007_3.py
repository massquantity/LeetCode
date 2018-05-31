class Solution:  
    def reverse(self, x):  
        revx = int(str(abs(x))[::-1])  
        if revx > math.pow(2, 31):  
            return 0  
        else:  
            return revx * cmp(x, 0)