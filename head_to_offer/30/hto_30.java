import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

class MinStack {
    Stack<Integer> stack1, stack2;
    public MinStack() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void push(int x) {
        stack1.add(x);
        if (stack2.empty() || x <= stack2.peek())
            stack2.add(x);
    }
    
    public void pop() {
        if (stack1.pop().equals(stack2.peek()))
            stack2.pop();
    }
    
    public int top() {
        return stack1.peek();
    }
    
    public int min() {
        return stack2.peek();
    }
}

public class leetcode {
    public static void main(String[] args) {
        MinStack obj = new MinStack();
        obj.push(-2);
        obj.push(0);
        obj.push(-3);
        System.out.println(obj.min());
        obj.pop();
        System.out.println(obj.top());
        System.out.println(obj.min());
    }
}