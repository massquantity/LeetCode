class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x % 10 ==0 && x != 0)) return false;

        long reverse = 0;
        long ans = x;
        while (x > 0)
        {
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }   
        return ans == reverse;
    }
}