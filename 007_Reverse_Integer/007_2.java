class Solution
{
    public int reverse(int x)
    {
        int res = 0, cur = 0;
        while (x != 0)
        {
            cur = x % 10;
            res = res * 10 + cur;
            x /= 10;
        }
        res = res % 10 == cur? res : 0;
        return res;
    }
}