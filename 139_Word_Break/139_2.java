class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int size = s.length();
        Set<String> wordSet = new HashSet<>(wordDict);
        Map<Integer, Boolean> memo = new HashMap<>();
        return dfs(0, s, size, wordSet, memo);
    }

    private boolean dfs(int i, String s, int size, Set<String> wordSet, Map<Integer, Boolean> memo) {
        if (i >= size) return true;
        if (memo.containsKey(i)) return memo.get(i);
        for (int j = i + 1; j < size + 1; j++) {
            if (wordSet.contains(s.substring(i, j)) && dfs(j, s, size, wordSet, memo)) {
                memo.put(i, true);
                return true;
            }
        }
        memo.put(i, false);
        return false;
    }
}
