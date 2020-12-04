from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        res = 0
        heights = [0] + heights + [0]
        stack = [0]
        for i in range(1, len(heights)):
            while heights[stack[-1]] > heights[i]:
                while stack[-1] == stack[-2]:
                    stack.pop()
                height = heights[stack.pop()]
                width = i - stack[-1] - 1
                res = max(res, height * width)
            stack.append(i)
        return res