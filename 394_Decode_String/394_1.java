class Solution {
    public String decodeString(String s) {
        Deque<Integer> numStack = new ArrayDeque<>();
        Deque<String> resStack = new ArrayDeque<>();
        int num = 0;
        StringBuilder res = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0');
            } else if (c == '[') {
                numStack.addLast(num);
                resStack.addLast(res.toString());
                num = 0;
                res = new StringBuilder();
            } else if (c == ']') {
                StringBuilder tmp = new StringBuilder();
                int curNum = numStack.removeLast();
                for (int i = 0; i < curNum; i++) {
                    tmp.append(res);
                }
                res = new StringBuilder(resStack.removeLast() + tmp);
            } else {
                res.append(c);
            }
        }
        return res.toString();
    }
}
