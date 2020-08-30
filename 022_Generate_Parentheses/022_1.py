from typing import List, Dict

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = [('', 0, 0)]
        res = []
        while stack:
            p, l, r = stack.pop()
            if l == n and r == n:
                res.append(p)
                continue
            
            if l < n:
                stack.append((p + '(', l + 1, r))
            if r < l:
                stack.append((p + ')', l, r + 1))
        return res