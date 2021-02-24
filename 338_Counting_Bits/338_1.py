from typing import List

class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0] * (num + 1)
        for n in range(1, num + 1):
            res[n] = res[n >> 1] + (n & 1)
        return res
