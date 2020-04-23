#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *start, *end;
        start = end = head;
        for (int i = 0; i < k; i++) {
            if (!end) return head;
            end = end->next;
        }
        ListNode *newHead = reverse(start, end);
        start->next = reverseKGroup(end, k);
        return newHead;
    }

    ListNode *reverse(ListNode *start, ListNode *end) {
        ListNode *pre = nullptr, *cur = start;
        while (cur != end) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;
    Solution s;
    ListNode *node = s.reverseKGroup(node1, 3);
    while (true) {
        cout << node->val;
        if (node->next) cout << " -> ";
        else            break;
        node = node->next;
    }
}
