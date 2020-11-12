from typing import List, Dict


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        k -= 1
        factorial = [1]
        for i in range(1, n):
            factorial.append(factorial[-1] * i)
        
        nums = []
        for i in range(1, n+1):
            nums.append(i)
        
        res = []
        for i in range(n - 1, -1, -1):
            index = k // factorial[i]
            res.append(str(nums[index]))
            nums.pop(index)
            k -= index * factorial[i]
        return "".join(res)
        

if __name__ == "__main__":
    s = Solution()
    print(s.getPermutation(3, 3))
