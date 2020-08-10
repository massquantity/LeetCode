class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        if (!head) return {};
        vector<int> res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(2);
    node1->next = node2; node2->next = node3;
    Solution s;
    for (auto &res : s.reversePrint(node1))
        cout << res << " ";
}