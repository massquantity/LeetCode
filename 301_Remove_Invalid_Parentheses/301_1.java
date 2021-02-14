class Solution {
    public List<String> removeInvalidParentheses(String s) {
        Set<String> level = new HashSet<>();
        level.add(s);
        while (true) {
            List<String> valid = new ArrayList<>();
            for (String str : level) {
                if (isValid(str)) {
                    valid.add(str);
                }
            }
            if (!valid.isEmpty()) return valid;
            Set<String> nextLevel = new HashSet<>();
            for (String item: level) {
                for (int i = 0; i < item.length(); i++) {
                    if (item.charAt(i) == '(' || item.charAt(i) == ')') {
                        nextLevel.add(item.substring(0, i) + item.substring(i + 1));
                    }
                }
            }
            level = nextLevel;
            if (level.isEmpty()) return new ArrayList<>();
        }
    }

    private boolean isValid(String str) {
        int count = 0;
        for (char c : str.toCharArray()) {
            if      (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
}
