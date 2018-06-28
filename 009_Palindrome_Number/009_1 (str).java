class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;

        String s = String.valueOf(x);
        String a = new StringBuffer(s).reverse().toString();
        if (s.equals(a))
            return true;
        else
            return false;
    }
}