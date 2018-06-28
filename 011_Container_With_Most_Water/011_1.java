class Solution
{
    public int maxArea(int[] height)
    {
        int low, area = 0, area_2;
        for (int i = 0; i < height.length; i++)
        {
            for (int j = 1; j < height.length; j++)
            {
                if (height[i] <= height[j]) low = height[i];
                else                        low = height[j];
                area_2 = (j - i) * low;
                if (area < area_2) area = area_2;
            }
        }
        return area;
    }
}