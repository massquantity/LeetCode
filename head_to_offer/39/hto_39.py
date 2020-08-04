from typing import List, Dict
from queue import Queue
from collections import deque
import math
from collections import Counter

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        votes = 0
        for num in nums:
            if votes == 0: 
                res = num
            votes += 1 if num == res else -1
        return res

    def majorityElement2(self, nums: List[int]) -> int:
        return Counter(nums).most_common(1)[0][0]


if __name__ == "__main__":
    aa = [1,2,3,2,2,2,5,4,2]
    s = Solution()
    print(s.majorityElement(aa))
    print(s.majorityElement2(aa))
