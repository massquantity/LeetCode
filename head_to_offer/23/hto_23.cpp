#include <unordered_set>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        while (head != nullptr) {
            if (set.find(head) != set.end()) return head;
            set.emplace(head);
            head = head->next;
        }
        return nullptr;
    }
};