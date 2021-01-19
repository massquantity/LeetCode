import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Random;

class Solution {
    int l1, l2, l3;
    char[] c1, c2, c3;
    boolean[][] visited;
    boolean interleaved = false;
    public boolean isInterleave(String s1, String s2, String s3) {
        l1 = s1.length();
        l2 = s2.length();
        l3 = s3.length();
        if (l1 + l2 != l3) return false;
        c1 = s1.toCharArray();
        c2 = s2.toCharArray();
        c3 = s3.toCharArray();
        visited = new boolean[l1 + 1][l2 + 1];
        dfs(0, 0, 0);
        return interleaved;
    }

    private void dfs(int i, int j, int k) {
        if (k == l3)  {
            interleaved = true;
            return;
        }
        if (visited[i][j]) return;
        visited[i][j] = true;
        if (i < l1 && c1[i] == c3[k]) dfs(i + 1, j, k + 1);
        if (j < l2 && c2[j] == c3[k]) dfs(i, j + 1, k + 1);
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    }
}
