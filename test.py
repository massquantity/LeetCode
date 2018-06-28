class Solution:
    def maxArea(self, height):
        i = 0
        j = len(height) - 1
        area = min(height[i], height[j]) * j
        if height[i] <= height[j]:
            i += 1
        else:
            j -= 1
        area_2 = min(height[i], height[j]) * (j - i)
        if area < area_2:
            area = area_2
        return area