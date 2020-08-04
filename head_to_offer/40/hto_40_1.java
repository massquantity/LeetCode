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
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Comparator;

class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) return new int[0];
    //    Queue<Integer> pq = new PriorityQueue<>((v1, v2) -> (v2 - v1));
    //    Queue<Integer> pq = new PriorityQueue<>((v1, v2) -> Integer.compare(v2, v1));
        Queue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer v1, Integer v2) {
                return v2 - v1;
            }
        });
        for (int num : arr) {
            if (pq.size() < k) {
                pq.offer(num);
            } else if (num < pq.peek()) {
                pq.poll();
                pq.offer(num);
            }
        }
        int[] res = new int[k];
        int idx = 0;
        for (int num : pq) {
            res[idx++] = num;
        }
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[] array = {0, 1, 2, 1, 3, 6, 8, 4};
        Solution s = new Solution();
        System.out.println(Arrays.toString(s.getLeastNumbers(array, 3)));
    }
}


