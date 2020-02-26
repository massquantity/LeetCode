struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) { };
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        size_t listLength = lists.size();
        if (listLength == 0)  return NULL;
        int interval = 1;
        while (interval < listLength) {
            for (int i = 0; i < listLength - interval; i += (interval * 2))
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            interval *= 2;
        }
        return lists[0];
    }

    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
                ListNode *dummy, *cur;
        dummy = cur = new ListNode(INT32_MIN);
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (!l1)
            cur->next = l2;
        if (!l2)
            cur->next = l1;
        return dummy->next;
    }
};