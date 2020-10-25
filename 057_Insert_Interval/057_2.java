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
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0) return new int[][]{newInterval};
        Boolean inserted = false;
        List<int[]> res = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            int[] arr = intervals[i];
            if (!inserted && arr[0] >= newInterval[0]) {
                if (res.isEmpty() || res.get(res.size() - 1)[1] < newInterval[0]) res.add(newInterval);
                else res.get(res.size() - 1)[1] = Math.max(res.get(res.size() - 1)[1], newInterval[1]);
                inserted = true;
            }
            if (res.isEmpty() || res.get(res.size() - 1)[1] < arr[0]) {
                res.add(arr);
            } else {
                res.get(res.size() - 1)[1] = Math.max(res.get(res.size() - 1)[1], arr[1]);
            }
        }
        if (!inserted && res.get(res.size() - 1)[1] < newInterval[0]) {
            res.add(newInterval);
        } else if (!inserted) {
            res.get(res.size() - 1)[1] = Math.max(res.get(res.size() - 1)[1], newInterval[1]);
        }
        return res.toArray(new int[0][]);
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[][] intervals = {{1,5}};
        int[] newInterval = {2,7};
        Solution so = new Solution();
        System.out.println(Arrays.deepToString(so.insert(intervals, newInterval)));
    }
}