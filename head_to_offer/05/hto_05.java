
class Solution {
    public String replaceSpace(String s) {
        StringBuilder sb = new StringBuilder();
        for (Character c : s.toCharArray()) {
            if (c == ' ') sb.append("%20");
            else          sb.append(c);
        }
        return sb.toString();
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.replaceSpace("We are happy"));
    }
}