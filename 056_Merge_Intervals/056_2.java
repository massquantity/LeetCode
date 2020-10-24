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
import java.util.Comparator;

class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) return new int[0][2];
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] i1, int[] i2) {
                return i1[0] - i2[0];
            }
        });
        List<int[]> res = new ArrayList<int[]>();
        for (int[] arr : intervals) {
            if (res.isEmpty() || res.get(res.size() - 1)[1] < arr[0]) {
                res.add(arr);
            } else {
                res.get(res.size() - 1)[1] = Math.max(res.get(res.size() - 1)[1], arr[1]);
            }
        }
        return res.toArray(new int[0][]);
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[][] intervals = {{1,3},{2,6},{8,10},{15,18}};
        Solution so = new Solution();
        System.out.println(Arrays.deepToString(so.merge(intervals)));
    }
}