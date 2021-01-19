struct LinkedNode {
    int key;
    int val;
    LinkedNode *prev;
    LinkedNode *next;
    LinkedNode(int key_, int val_) {
        key = key_;
        val = val_;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new LinkedNode(-1, -1);
        tail = new LinkedNode(-1, -1);
        head->next = tail;
        tail->prev = head;
        map.clear();
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            moveToHead(map[key]);
            return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map[key]->val = value;
            moveToHead(map[key]);
            return;
        }
        LinkedNode *node = new LinkedNode(key, value);
        map.insert(make_pair(key, node));
        addToHead(node);
        if (map.size() > cap) {
            LinkedNode *rev = removeTail();
            map.erase(rev->key);
            delete rev;
        }
    }

    void removeNode(LinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(LinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(LinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    LinkedNode *removeTail() {
        LinkedNode *res = tail->prev;
        removeNode(res);
        return res;
    }

private: 
    int cap;
    unordered_map<int, LinkedNode*> map;
    LinkedNode *head, *tail;
};
