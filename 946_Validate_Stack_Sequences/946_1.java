import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Deque<Integer> stack = new ArrayDeque<>();
        int i = 0;
        for (int num : pushed) {
            stack.push(num);
            while (i < popped.length && !stack.isEmpty() && stack.peek() == popped[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.isEmpty();
    }
}

public class leetcode {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] pushed = {1,2,3,4,5};
        int[] popped = {4,5,3,2,1};
        System.out.println(s.validateStackSequences(pushed, popped));
    }
}