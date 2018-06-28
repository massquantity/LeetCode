class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int [] whole = nums1 + nums2;
        int ll = whole.length();
        if (ll % 2 == 0 && ll != 0)
            return (whole[ll / 2 - 1] + whole[ll / 2]) / 2;
        else
            return whole[ll / 2];
    }
}


class Solution
{
    public List<Interval> merge(List<Interval> intervals)
    {
        if (intervals.size() <= 1) return intervals;

        intervals.sort((a, b) -> Integer.compare(a.start, b.start));
        List<Interval> res = new ArrayList<>();
        Interval init = intervals.get(0);
        for (Interval array : intervals)
            if (init.end < array.start)
            {
                res.add(init);
                init = array;
            }
            else init.end = Math.max(init.end, array.end);
        res.add(init);
        return res
    }
}


public class RedBlackBST<Key extends Comparable<Key>, Value>
{
    private static final boolean RED   = true;
    private static final boolean BLACK = false;

    private Node root;

    private class Node
    {
        private Key key;
        private Value val;
        private Node left, right;
        private boolean color;
        private int size;

        public Node(Key key, Value val, boolean color, int size)
        {
            this.key = key;
            this.val = val;
            this.color = color;
            this.size = size;
        }
    }

    private boolean isRed(Node x)
    {
        if (x == null) return false;
        return x.color == RED;
    }

    private int size(Node x)
    {
        if (x == null) return 0;
        return x.size;
    }

    public int size()
    { return size(root); }

    private Node rotateLeft(Node h)
    {
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    private Node rotateRight(Node h)
    {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    private void flipColors(Node h)
    {
        h.color = RED;
        h.left.color = BLACK;
        h.right.color = BLACK;
    }

    public void put(Key key, Value val)
    {
        root = put(root, key, val);
        root.color = BALCK;
    }

    private Node put(Node h, Key key, Value val)
    {
        if (h == null) return new Node(key, val, RED, 1);

        int cmp = key.compareTo(h.key);
        if      (cmp < 0) h.left  = put(h.left, key, val);
        else if (cmp > 0) h.right = put(h.right, key, val);
        else              h.val = val;

        if (isRed(h.right) && !isRed(h.left))    h = rotateLeft(h);
        if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
        if (isRed(h.left) && isRed(h.right))     flipColors(h);
        h.size = size(h.left) + size(h.right) + 1;
        return h;
    }
    
    private void keys(Node x, Queue<Key> queue, Key lo, Key hi)
    {
        if (x == null) return;
        int cmplo = lo.compareTo(x.key);
        int cmphi = hi.compareTo(x.key);
        if (cmplo < 0) keys(x.left, queue, lo, hi);
        if (cmplo <= 0 && cmphi >= 0) queue.enqueue(x.key);
        if (cmphi > 0) keys(x.right, queue, lo, hi);
    }

    public static void main(String[] args)
    {
        RedBlackBST<String, Integer> st = new RedBlackBST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++)
        {
            String key = StdIn.readString();
            st.put(key, i);
        }    
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
        StdOut.println(); 
    }
}