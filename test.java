class Solution
{
    public int maxArea(int[] height)
    {
        int i = 0;
        int j = height.length - 1;
        int area = Math.min(height[i], height[j]) * j, area_2;

        while(i < j)
        {
            if (height[i] <= height[j]) i++;
            else                        j--;
            area_2 = Math.min(height[i], height[j]) * (j - i);
            if (area < area_2) area = area_2;
        }
        return area;
    }
}

public class test
{
    public static void main(String[] args)
    {
        Solution aa = new Solution();
        int[] bb = {1,155,3,99,33};
        System.out.println(aa.maxArea(bb));
    }
}