class Solution {
    public int strToInt(String str) {
        if (str == null) return 0;
        int n = str.length();
        int i, res = 0;
        boolean is_negative = false;
        for (i = 0; i < n && Character.isWhitespace(str.charAt(i)); ++i);
        if (i == n) return 0;
        if (str.charAt(i) == '-') is_negative = true;
        if (str.charAt(i) == '+' || str.charAt(i) == '-') i++;
        while (i < n && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            int tmp = str.charAt(i) - '0';  // 减去 '0' 的ASCII码
            if (!is_negative && (res > 214748364 || (res == 214748364 && tmp >= 7))) {
                return 2147483647;
            }
            if (is_negative && (-res < -214748364 || (-res == -214748364 && tmp >= 8))) {
                return -2147483648;
            }
            res = res * 10 + tmp;
            ++i;
        }
        return is_negative ? -res : res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        String str1 = new String("-123");
        String str2 = new String("2147483648");
        System.out.println(s.strToInt(str1) + " " + s.strToInt(str2));
    }
}