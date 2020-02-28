#include <functional>
#include <queue>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) { };
};


class Solution {
public:
    /*
    struct cmp{
        bool operator()(ListNode *a,ListNode *b){
            return a->val > b->val;
        }
    }; */

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode *dummy = new ListNode(INT32_MIN);
        ListNode *cur = dummy;
        for (auto l : lists) {
            if (l == NULL) continue;
            pq.push(l);
        }
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next)
                pq.push(cur->next);
        }
    //    return dummy->next;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};