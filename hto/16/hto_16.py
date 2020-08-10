class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:  return 1
        if n == 1:  return x
        if n == -1: return 1 / x
        half = self.myPow(x, n >> 1)
        rest = self.myPow(x, n % 2)
        return rest * half * half


if __name__ == "__main__":
    s = Solution()
    print(s.myPow(2.0, 10))