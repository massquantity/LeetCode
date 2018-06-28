class Solution
{
    public int lengthOfLongestSubstring(String s)
    {
        int length = 0;
        int left = 0;
        int[] prev = new int[300];

        for (int i = 0; i < 300; i++)
            prev[i] = -1;

        for (int j = 0; j < s.length(); j++)
        {
            if (prev[s.charAt(j)] >= left)
                left = prev[s.charAt(j)] + 1;
            prev[s.charAt(j)] = j;
            if (length < j - left + 1)
                length = j - left + 1;
        }
        return length;
    }
}