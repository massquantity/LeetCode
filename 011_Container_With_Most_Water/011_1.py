class Solution:
    def maxArea(self, height):
        area = 0
        for i, left in enumerate(height):
            for j, right in enumerate(height[1:]):
                if left <= right:
                    low = left
                else:
                    low = right
                area_2 = (j - i) * low
                if area_2 > area:
                    area = area_2
        return area