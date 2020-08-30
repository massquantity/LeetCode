class Solution {
    private StringBuilder sb = new StringBuilder();
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        if (n == 0) return res;
        backtrack(res, 0, 0, n);
        return res;
    }

    private void backtrack(List<String> res, int l, int r, int n) {
        if (l > n || r > n) return;
        if (l == n && r == n) {
            res.add(sb.toString());
            return;
        }
        if (l >= r) {
            sb.append('(');
            backtrack(res, l+1, r, n);
            sb.deleteCharAt(sb.length() - 1);

            sb.append(')');
            backtrack(res, l, r+1, n);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}