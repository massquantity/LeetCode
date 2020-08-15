class MaxQueue {
    Deque<Integer> queue;
    Deque<Integer> max_queue;
    public MaxQueue() {
        queue = new ArrayDeque<>();
        max_queue = new ArrayDeque<>();
    }
    
    public int max_value() {
        return queue.isEmpty() ? -1 : max_queue.peek();
    }
    
    public void push_back(int value) {
        while (!max_queue.isEmpty() && max_queue.peekLast() < value)
            max_queue.pollLast();
        max_queue.offer(value);
        queue.offer(value);
    }
    
    public int pop_front() {
        if (queue.isEmpty()) return -1;
        int val = queue.poll();
        if (max_queue.peek() == val) max_queue.poll();
        return val;
    }
}

