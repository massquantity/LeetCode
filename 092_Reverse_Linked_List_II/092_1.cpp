class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

    ListNode *reverseN(ListNode *head, int m) {
        if (m == 1) {
            successor = head->next;
            return head;
        }

        ListNode *last = reverseN(head->next, m - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

private:
    ListNode *successor = nullptr;
};