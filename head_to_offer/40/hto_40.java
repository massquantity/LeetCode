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

class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) return new int[0];
        Arrays.sort(arr);
        return Arrays.copyOfRange(arr, 0, k);
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[] array = {0, 1, 2, 1, 3, 6, 8, 4};
        Solution s = new Solution();
        System.out.println(Arrays.toString(s.getLeastNumbers(array, 3)));
    }
}


