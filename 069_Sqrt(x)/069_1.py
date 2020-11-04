class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        cur = 1
        while True:
            pre = cur
            cur = (cur + x / cur) / 2
            if abs(cur - pre) < 1e-7:
                return int(cur)