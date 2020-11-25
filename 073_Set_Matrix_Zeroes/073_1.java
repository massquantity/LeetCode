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
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        Boolean rowFlag = false, colFlag = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                rowFlag = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                colFlag = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        
        }

        if (rowFlag) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (colFlag) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
        s.setZeroes(matrix);
        System.out.println(Arrays.deepToString(matrix));
    }
}