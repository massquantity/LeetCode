class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int len = s.length();
        Boolean[] visited = new Boolean[len];
        Arrays.fill(visited, false);
        Set<String> wordSet = new HashSet<>(wordDict);
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offerLast(0);
        while (!queue.isEmpty()) {
            int cur = queue.removeFirst();
            if (visited[cur]) continue;
            visited[cur] = true;
            for (int i = cur + 1; i <= len; i++) {
                String substr = s.substring(cur, i);
                if (wordSet.contains(substr)) {
                    if (i < len) {
                        queue.offerLast(i);
                    } else {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

public class MainClass {
    public static void main(String[] args) {
        Solution s = new Solution();
        List<String> wordDict = new ArrayList<>();
        wordDict.add("leet");
        wordDict.add("code");
        System.out.println(s.wordBreak("leetcode", wordDict));
    }
}
