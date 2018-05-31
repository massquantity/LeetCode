class Solution
{
    public int reverse(int x)
    {
        long res = 0;
        while (Math.abs(x) != 0)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (Math.abs(res) > Integer.MAX_VALUE)
            return 0;  
        return (int) res;
    }
}