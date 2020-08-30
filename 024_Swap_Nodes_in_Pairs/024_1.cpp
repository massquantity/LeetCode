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
#include <sstream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        pre->next = head;
        while (head && head->next) {
            ListNode *end = head->next->next;
            pre->next = head->next;
            head->next->next = head;
            head->next = end;
            pre = head;
            head = head->next;
        }
        return dummy->next;
    }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s;
    ListNode *res = s.swapPairs(node1);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
}

