#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <bitset>
#include <array>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mm;
        Node *cur = head;
        while (cur) {
            mm[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            mm[cur]->next = mm[cur->next];
            mm[cur]->random = mm[cur->random];
            cur = cur->next;
        }
        return mm[head];
    }
};

int main() {
    Node *node1 = new Node(7);
    Node *node2 = new Node(13);
    Node *node3 = new Node(11);
    Node *node4 = new Node(10);
    Node *node5 = new Node(1);

    node1->next = node2; node2->next = node3; node3->next = node4;
    node4->next = node5;
    node1->random = node4; node2->random = node1;
    node3->random = node5; node4->random = node3; node5->random = node1;
    Solution s;
    struct Node *node = s.copyRandomList(node1);
    while (node) {
        printf("%d ", node->val);
        node = node->random;
    }
}




