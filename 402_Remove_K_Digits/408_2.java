class Solution {
    public String removeKdigits(String num, int k) {
        if (num.length() == k) return "0";
        Deque<Character> stack = new ArrayDeque<>();
        int final_size = num.length() - k;
        for (char c : num.toCharArray()) {
            while (k > 0 && !stack.isEmpty() && stack.peekLast() > c) {
                stack.pollLast();
                k--;
            }
            stack.addLast(c);
        }

        StringBuilder sb = new StringBuilder();
        Boolean frontZero = true;
        for (int i = 0; i < final_size; i++) {
            if (frontZero && stack.peekFirst() == '0') {
                stack.pollFirst();
            } else {
                frontZero = false;
                sb.append(stack.pollFirst());
            }
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }
}