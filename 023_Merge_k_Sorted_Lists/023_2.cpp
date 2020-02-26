struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
    ListNode * mergeKLists(vector<ListNode *> &lists) {
        size_t listLength = lists.size();
        if (listLength == 0)  return nullptr;
        if (listLength == 1)  return lists[0];
        if (listLength == 2)
            return mergeTwoLists(lists[0], lists[1]);

        int mid = listLength / 2;
        vector<ListNode *> v1;
        v1.reserve(mid);
        for (int i = 0; i < mid; ++i)
            v1.push_back(lists[i]);
        vector<ListNode *> v2;
        for (int i = mid; i < listLength; ++i)
            v2.push_back(lists[i]);

        return mergeTwoLists(mergeKLists(v1), mergeKLists(v2));
    }

    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1)  return l2;
        if (!l2)  return l1;

        ListNode *head = nullptr;
        if (l1->val <= l2->val) {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        } else {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(5);
    ListNode *l3 = new ListNode(7);
    l1->next = l2;
    l2->next = l3;
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(4);
    ListNode *l6 = new ListNode(6);
    l4->next = l5;
    l5->next = l6;
    ListNode *l7 = new ListNode(3);
    ListNode *l8 = new ListNode(8);
    ListNode *l9 = new ListNode(9);
    l7->next = l8;
    l8->next = l9;
    vector<ListNode *> v{l1, l4, l7};
    Solution s;
    ListNode *res = s.mergeKLists(v);
    do {
        cout << res->val << " ";
    } while ((res = res->next));
}