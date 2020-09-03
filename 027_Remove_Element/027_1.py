from typing import List, Dict

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j=len(nums)
        for i in range(j-1,-1,-1):
            if nums[i] == val:
                nums.pop(i)    
        return len(nums)