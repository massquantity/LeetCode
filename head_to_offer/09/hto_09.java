import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class CQueue {
    Deque<Integer> stack1;
    Deque<Integer> stack2;

    public CQueue() {
        stack1 = new ArrayDeque<>();
        stack2 = new ArrayDeque<>();
    }
    
    public void appendTail(int value) {
        stack1.add(value);
    }
    
    public int deleteHead() {
        if (stack2.isEmpty()) {
            if (stack1.isEmpty()) return -1;
            while (!stack1.isEmpty())
                stack2.add(stack1.pop());
        }
        return stack2.pop();
    }
}

public class leetcode {
    public static void main(String[] args) {
        CQueue queue = new CQueue();
        queue.appendTail(1);
        System.out.println(queue.deleteHead());
        System.out.println(queue.deleteHead());
    }
}