class Solution {
    public String reverseWords(String s) {
        String[] ss = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = ss.length - 1; i >= 0; i--) {
            sb.append(ss[i]);
            if (i > 0)
                sb.append(" ");
        }
        return sb.toString();
    }

    public String reverseWords2(String s) {
        String[] ss = s.trim().split(" +");
        Collections.reverse(Arrays.asList(ss));
        return String.join(" ", ss);
    }
}
