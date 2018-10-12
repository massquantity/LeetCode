class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;

        ListNode res = head;
        ListNode prev = null;
        while (res != null && res.next != null)
        {
            if (res.val == res.next.val)
            {
                int currVal = res.val;
                while (res != null && res.val == currVal)
                    res = res.next; 
                if (prev != null)
                    prev.next = res;
                else
                    head = res;
            }
            else
            {
                prev = res;
                res = res.next;
            }
        }
        return head;
    }
}