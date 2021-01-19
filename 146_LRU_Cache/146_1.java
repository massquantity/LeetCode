class LRUCache {
    private class ListNode {
        int key, val;
        ListNode prev, next;
        public ListNode() { }
        public ListNode(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }

    private Map<Integer, ListNode> map = new HashMap<>();
    private int capacity;
    private ListNode head, tail;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new ListNode();
        tail = new ListNode();
        head.next = tail;
        tail.next = head;
    }
    
    public int get(int key) {
        ListNode node = map.get(key);
        if (node == null) return -1;
        moveToHead(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        ListNode node = map.get(key);
        if (node == null) {
            ListNode newNode = new ListNode(key, value);
            map.put(key, newNode);
            addToHead(newNode);
            if (map.size() > capacity) {
                ListNode tail = removeTail();
                map.remove(tail.key);
            }
        } else {
            node.val = value;
            moveToHead(node);
        }
    }

    private void addToHead(ListNode node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }

    private void removeNode(ListNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void moveToHead(ListNode node) {
        removeNode(node);
        addToHead(node);
    }

    private ListNode removeTail() {
        ListNode res = tail.prev;
        removeNode(res);
        return res;
    }
}
