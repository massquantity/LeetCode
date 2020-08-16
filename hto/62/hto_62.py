class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        pos = 0
        for i in range(2, n+1):
            pos = (pos + m) % i
        return pos