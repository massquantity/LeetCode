class ListNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.hashmap = dict()
        self.head = ListNode(-1, -1)
        self.tail = ListNode(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def move_node_to_head(self, key: int) -> None:
        node = self.hashmap[key]
        node.prev.next = node.next
        node.next.prev = node.prev
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
        
    def get(self, key: int) -> int:
        if key in self.hashmap:
            self.move_node_to_head(key)
            return self.hashmap[key].val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            self.hashmap[key].val = value
            self.move_node_to_head(key)
        else:
            if len(self.hashmap) == self.capacity:
                self.hashmap.pop(self.tail.prev.key)
                self.tail.prev = self.tail.prev.prev
                self.tail.prev.next = self.tail
            new_node = ListNode(key, value)
            self.hashmap[key] = new_node
            new_node.prev = self.head
            new_node.next = self.head.next
            self.head.next.prev = new_node
            self.head.next = new_node
