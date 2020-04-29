import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public boolean exist(char[][] board, String word) {
        char[] words = word.toCharArray();
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (backtrack(board, words, i, j, 0)) return true;
            }
        }
        return false;
    }

    private boolean backtrack(char[][] board, char[] word, int i, int j, int k) {
        if (i < 0 || i >= board.length || j < 0 || 
            j >= board[0].length || board[i][j] != word[k]) return false;
        if (k == word.length - 1) return true;
        char tmp = board[i][j];
        board[i][j] = '/';
        boolean res = backtrack(board, word, i + 1, j, k + 1) ||
                      backtrack(board, word, i - 1, j, k + 1) ||
                      backtrack(board, word, i, j + 1, k + 1) ||
                      backtrack(board, word, i, j - 1, k + 1);
        board[i][j] = tmp;
        return res;
    }
}

public class leetcode {
    public static void main(String[] args) {
        char[][] board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        String word = "ABCCED";
        Solution s = new Solution();
        System.out.println(s.exist(board, word));
    }
}