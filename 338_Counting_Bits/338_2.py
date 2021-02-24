class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0] * (num + 1)
        for n in range(1, num + 1):
            count = 0
            m = n
            while m > 0:
                m &= (m - 1)
                count += 1
            res[n] = count
        return res
