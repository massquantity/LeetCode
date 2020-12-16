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
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        if (numCourses == 0) return new int[0];
        HashSet<Integer>[] adj = new HashSet[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adj[i] = new HashSet<>();
        }

        int[] inDegree = new int[numCourses];
        for (int[] p : prerequisites) {
            inDegree[p[0]]++;
            adj[p[1]].add(p[0]);
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        int[] res = new int[numCourses];
        int count = 0;
        while (!queue.isEmpty()) {
            Integer head = queue.poll();
            res[count++] = head;
            Set<Integer> successors = adj[head];
            for (Integer c : successors) {
                inDegree[c]--;
                if (inDegree[c] == 0) {
                    queue.offer(c);
                }
            }
        }

        if (count == numCourses) {
            return res;
        } 
        return new int[0];
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
        System.out.println(Arrays.toString(s.findOrder(4, prerequisites)));
    }
}
