class Solution {
    public String removeKdigits(String num, int k) {
        if (num.length() == k) return "0";
        StringBuilder sb = new StringBuilder();
        int m = num.length() - k;
        for (char c : num.toCharArray()) {
            while (k > 0 && sb.length() > 0 && sb.charAt(sb.length() - 1) > c) {
                sb = sb.deleteCharAt(sb.length() - 1);
                k--;
            }
            sb.append(c);
        }
        sb = sb.delete(m, sb.length());
    //    while (sb.length() != 0 && sb.charAt(0) == '0') {
    //        sb = sb.deleteCharAt(0);
    //    }
        int len = sb.length();
        if (len != 0 && sb.charAt(0) == '0') {
            int i = 0;
            while (i < len && sb.charAt(i) == '0') i++;
            sb.delete(0, i);
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }
}