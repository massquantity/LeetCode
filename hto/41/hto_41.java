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
import java.util.LinkedHashMap;

class MedianFinder {
    int count;
    Queue<Integer> minHeap, maxHeap;
    public MedianFinder() {
        count = 0;
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>((x, y) -> (y - x));
    }
    
    public void addNum(int num) {
        count++;
        if (minHeap.size() != maxHeap.size()) {
            minHeap.add(num);
            maxHeap.add(minHeap.poll());
        } else {
            maxHeap.add(num);
            minHeap.add(maxHeap.poll());
        }
    }
    
    public double findMedian() {
        if ((count & 1) == 0) {
            return (double) (minHeap.peek() + maxHeap.peek()) / 2;
        } else {
            return (double) minHeap.peek();
        }
    }
}

public class leetcode {
    public static void main(String[] args) {
        MedianFinder obj = new MedianFinder();
        obj.addNum(1);
        obj.addNum(2);
        System.out.println(obj.findMedian());
        obj.addNum(3);
        System.out.println(obj.findMedian());
    }
}


