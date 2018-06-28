class Solution
{
    public int maxArea(int[] height)
    {
        int i = 0;
        int j = height.length - 1;
        int area = Math.min(height[i], height[j]) * j, area_2;

        while (i < j)
        {
            if (height[i] <= height[j]) i++;
            else                        j--;
            area_2 = Math.min(height[i], height[j]) * (j - i);
            if (area < area_2) area = area_2;
        }
        return area;
    }
}